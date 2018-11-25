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
#define MAXN 1255

bool used[MAXN];
vector<int> edg[MAXN];

int llink[MAXN];
int rlink[MAXN];

char C[42][42];

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

void solve(){
	int n, m;
	cin >> n >> m;
	getchar();
	int num = 0;

	for(auto &v : edg)
		v.clear();
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> C[i][j];
			if(C[i][j] == '*')
				num++;
		}
		getchar();
	}
	for (int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(C[i][j] == '*' && C[i-1][j] == '*'){
				int l = (i*m+j) ;
				int r = ((i-1)*m+j) ;
				if((i-j)%2 == 0){
					edg[(l >> 1)+1].PB((r >> 1)+1);
				}else{
					edg[(r >> 1)+1].PB((l >> 1)+1);
				}
			}
		}
	}
	for(int j = 1; j < m; ++j){
		for (int i = 0; i < n; ++i){
			if(C[i][j] == '*' && C[i][j-1] == '*'){
				int l = (i*m+j) ;
				int r = (i*m+j-1) ;
				if((i-j)%2 == 0){
					edg[(l >> 1)+1].PB((r >> 1)+1);
				}else{
					edg[(r >> 1)+1].PB((l >> 1)+1);
				}
			}
		}
	}

	cout << num - Bipartite((n*m+1)>> 1, (n*m)>>1) << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
