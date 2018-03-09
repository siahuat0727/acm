#include <stdio.h>
#define MAX_BOLTS 500
#define MAX_NUTS  500
/* global copy of the input data */
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
#define MAXN 505

bool used[MAXN];
vector<int> edg[MAXN];

int llink[MAXN];
int rlink[MAXN];

bool DFS(int now){
	for(int i = 0; i < edg[now].size(); ++i){
		// printf("qq %d\n", now);
		int next = edg[now][i];

		if(!used[next]){
			used[next] = true;
			if(!rlink[next] || DFS(rlink[next])){
				// printf("qq entered\n");
				llink[now] = next;
				rlink[next] = now;
				return true;
			}
		}
	}
	return false;
}

int Bipartite(int nL, int nR){
	memset(llink, 0, (nL+1)*sizeof(int));
	memset(rlink, 0, (nR+1)*sizeof(int));
	int ans = 0;
	for(int i = 1; i <= nL; ++i){
		 // for(int j : edg[i])
		 // 	cout << j << endl;
		memset(used, false, (nR+1)*sizeof(bool));
		if(DFS(i)){
			// printf("qq %d %d\n", i, llink[i]);
			++ans;
		}
	}
	return ans;
}

int main(){
	int cases,caseno;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i){
			edg[i].clear();
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				int t;
				cin >> t;
				if(t)
					edg[i].PB(j);
			}
		}

		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",Bipartite(n, m));
		printf("can be fitted together\n");
	}
	return 0;
}