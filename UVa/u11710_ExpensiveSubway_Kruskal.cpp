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
#define MAXN 405
int p[MAXN];

struct Edge
{
	int l, r, d;
}E;

vector<Edge> V;

bool cmp(Edge a, Edge b){
	return a.d < b.d;
}

int Find(int x){
	return x == p[x] ? x : p[x] = Find(p[x]);
}

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
	return x == y ? false : true;
}

int main() {
    int s, c;
    while(scanf("%d%d", &s, &c) && (s||c)){
    	V.clear();
    	map<string, int> M;
    	for (int i = 0; i < s; ++i){
	    	string str;
	    	cin >> str;
	    	M[str] = i;
    		p[i] = i;
    	}
    	for (int i = 0; i < c; ++i){
    		string str1, str2;
    		int d;
    		cin >> str1 >> str2 >> d;
    		Edge e = {M[str1], M[str2], d};
    		V.push_back(e);
    	}
    	string dummy;
    	cin >> dummy;
    	int choose = 0, cost = 0;
    	sort(V.begin(), V.end(), cmp);
    	for(int i = 0; i < c && choose != s-1; ++i){
    		if(Union(V[i].l, V[i].r)){
    			cost += V[i].d;
    			choose++;
    		}
    	}
    	if(choose == s-1){
    		printf("%d\n", cost);
    	}else
	    	printf("Impossible\n");
    }
    return 0;
}
