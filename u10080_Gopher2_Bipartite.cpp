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

#define MAXN 105

struct Coor
{
	double x, y;
};

Coor L[MAXN];
Coor R[MAXN];
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
		memset(used, false, (nR+1)*sizeof(bool));
		if(DFS(i)){
			// printf("qq ++\n");
			++ans;
		}
	}
	return ans;
}

double getDistance(Coor a, Coor b){
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main() {
	int n, m, s, v;
	while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF){
		for (int i = 1; i <= n; ++i){
			edg[i].clear();
			double tx, ty;
			scanf("%lf%lf", &tx, &ty);
			L[i].x = tx;
			L[i].y = ty;
		}
		for (int i = 1; i <= m; ++i){
			double tx, ty;
			scanf("%lf%lf", &tx, &ty);
			R[i].x = tx;
			R[i].y = ty;
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if(s >= getDistance(L[i], R[j]) / v){
					// printf("qq %d %d\n", i, j);
					edg[i].push_back(j);
				}
			}
		}
		int save = Bipartite(n, m);
		printf("%d\n", n - save);
	}
    return 0;
}
