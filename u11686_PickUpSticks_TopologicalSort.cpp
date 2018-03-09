#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define PB push_back
#define MAXN 1000005
#define WHITE 0
#define GRAY 1
#define BLACK 2

int Time;
int numV;
bool impossible;

struct V{
	int index;
	int color;
	int start;
	int finish;
};
V v[MAXN];

vector<V*> adj[MAXN];

void DFS_visit(V &u){
	u.color = GRAY;
	u.start = ++Time;
	for(V* cur : adj[u.index])
		if(!cur->color) // if(cur.color == WHITE)
			DFS_visit(*cur);
		else if(cur->color == GRAY)
			impossible = true;
	u.color = BLACK;
	u.finish = ++Time;
}

void DFS(){
	Time = 0;
	for (int i = 0; i < numV; ++i)
		v[i].color = WHITE;
	for (int i = 0; i < numV; ++i){
		if(impossible)
			return;
		if(!v[i].color) // if v[i].color == WHITE
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

void topology_sort(){
	sort(v, v+numV, cmp);
}

int main(){
	int n;
	while((cin >> numV >> n) && (numV || n)){
		memset(v, 0, sizeof v);
		memset(adj, 0, sizeof adj);
		input(n);
		impossible = false;
		DFS();
		if(impossible)
			puts("IMPOSSIBLE");
		else{
			topology_sort();
			for (int i = 0; i < numV; ++i)
				printf("%d\n", v[i].index);
		}
	}
}