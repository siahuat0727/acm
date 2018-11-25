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

bool used[MAXN];
vector<int> edg[MAXN];

int llink[MAXN];
int rlink[MAXN];
int lValue[MAXN];
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
			//printf("qq %d\n", i);
			++ans;
		}
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt){
		int n, m;
		cin >> n;
		for (int i = 1; i <= n; ++i){
			edg[i].clear();
			cin >> lValue[i];
		}
		cin >> m;
		for (int i = 1; i <= m; ++i){
			int t;
			cin >> t;
			for (int j = 1; j <= n; ++j){
				if(t == lValue[j] || !t || (lValue[j] && t % lValue[j] == 0))
					edg[j].PB(i);
			}
		}

		printf("Case %d: %d\n", tt, Bipartite(n, m));
	}
	return 0;
}