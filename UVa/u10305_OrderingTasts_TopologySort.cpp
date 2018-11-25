#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

#define PB push_back
#define MAXN 105
#define WHITE 0
#define GRAY 1
#define BLACK 2

int Time;
int numV;

struct V{
	int index;
	int color;
	int start;
	int finish;
};
V v[MAXN];

vector<V*> adj[MAXN];

void DFS_visit(V &u){
	// printf("qq V %d %d\n", u.index, u.color);
	u.color = GRAY;
	u.start = ++Time;
	// printf("qq V when time = %d, %d %d\n", Time, u.index, u.color);
	for(V* cur : adj[u.index])
		if(!cur->color) // if(cur.color == WHITE)
			DFS_visit(*cur);
	u.color = BLACK;
	u.finish = ++Time;
	// printf("qq V when time = %d, %d %d\n", Time, u.index, u.color);

}

void DFS(){
	// printf("qq D\n");
	Time = 0;
	for (int i = 0; i < numV; ++i)
		v[i].color = WHITE;
	for (int i = 0; i < numV; ++i)
		if(!v[i].color) {// if v[i].color == WHITE
			// printf("qq D %d %d\n", v[i].index, v[i].color);
			DFS_visit(v[i]);
		}
}

bool cmp(V a, V b){
	return a.finish > b.finish;
}

void input(int n){
	for (int i = 0; i < numV; ++i)
		v[i].index = i+1;
	while(n--){
		int t;
		int nxt;
		cin >> t >> nxt;
		adj[t].PB(&v[nxt-1]);
	}
}

void printResult(){
	for (int i = 0; i < numV; ++i)
	{
		// printf("qq %d %d %d\n", v[i].index, v[i].start, v[i].finish);
	}
}

void topology_sort(){
	// printf("qq t\n");
	DFS();
	printResult();
	sort(v, v+numV, cmp);
}

int main(){
	int n;
	// printf("qq m\n");
	while((cin >> numV >> n) && (numV || n)){
		input(n);
		// printf("qq mw\n");
		topology_sort();
		printf("%d", v[0].index);
		for (int i = 1; i < numV; ++i)
			printf(" %d", v[i].index);
		puts("");
	}
}