#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXM 1005
#define MAXN 105
#define INF 1000000000
#define PB push_back

int pa[MAXN];
bool v[MAXN];

using namespace std;

int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pigNum[MAXM];
vector<int> V[MAXM];

bool DFS(int cur, int t, int n){
	v[cur] = true;
	if(cur == t)
		return true;
	for(int i = 1; i <= n; ++i){
		if(v[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			pa[i] = cur;
			if(DFS(i, t, n))
				return true;
		}
	}
	return false;
}

int FindFlow(int s, int t, int n){
	int pre;
	int f = INF;
	for(int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i]>0)
			f = min(f, cap[pre][i] - flow[pre][i]);
		else
			f = min(f, flow[i][pre]);
	}
	for (int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i] > 0)
			flow[pre][i] += f;
		else
			flow[i][pre] -= f;
	}
	return f;
}

int FordFulkerson(int s, int t, int n){
	int ret = 0;
	while(1){
		// printf("ret = %d\n", ret);
		memset(v, 0, sizeof(v));
		if(!DFS(s, t, n)) // source, end, totalV
			break;
		ret += FindFlow(s, t, n);
	}
	return ret;
}

// int mmain() {
//     int m, n;
//     scanf("%d%d", &m, &n);
// 	const int s = m + 1;
// 	const int t = m + 2;
// 	for (int i = 1; i <= m; ++i){
// 		int tmp;
// 		scanf("%d", &tmp);
// 		cap[i][t] = tmp;
// 	}
// 	int ans = 0;
// 	for(int i = 1; i <= n; ++i){
// 		int k;
// 		scanf("%d", &k);
// 		int arr[k];
// 		for (int i = 0; i < k; ++i){
// 			scanf("%d", &arr[i]);
// 			if(!i)
// 				cap[arr[i-1]][arr[i]] = cap[arr[i]][arr[i-1]] = INF;
// 		}
// 		// for (int j = 1; j <= k; ++j){
// 		// 	int tmp;
// 		// 	scanf("%d", &tmp);
// 		// 	cap[m + i][tmp] = INF;
// 		// }

// 		int c;
// 		scanf("%d", &c);
// 		cap[s][arr[0]] = c;
// 		// printf("%d\n", ans);
// 		ans += FordFulkerson(s, t, t);
// 		printf("%d\n", ans);
// 		cap[s][arr[0]] = 0;
		

// 	}

// 	// int ans = FordFulkerson(s, t, t);
// 	printf("%d\n", ans);
//     return 0;
// }

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
	const int s = n + 1;
	const int t = n + 2;
	for (int i = 1; i <= m; ++i){
		int tmp;
		scanf("%d", &tmp);
		pigNum[i] = tmp;
	}
	for(int i = 1; i <= n; ++i){
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j){
			int tmp;
			scanf("%d", &tmp);
			V[tmp].PB(i);
		}

		int c;
		scanf("%d", &c);
		cap[i][t] = c;
		// printf("qq cap[%d][%d] = %d\n", i, t, c);
	}
	for (int i = 1; i <= m; ++i){
		int sz = V[i].size();
		// printf("qq sz = %d\n", sz);
		if(!sz)
			continue;
		cap[s][V[i][0]] += pigNum[i];
		// printf("qq cap[%d][%d] = %d\n", s, V[i][0], pigNum[i]);
		for(int j = 1; j < sz; ++j){
			cap[V[i][j-1]][V[i][j]] = INF;
			// printf("qq cap[%d][%d] = %d\n", V[i][j-1], V[i][j], INF);
		}
	}
	int ans = FordFulkerson(s, t, t);
	printf("%d\n", ans);

    return 0;
}
