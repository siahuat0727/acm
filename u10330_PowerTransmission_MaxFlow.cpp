#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1005
#define INF 1000000000

int pa[MAXN];
bool v[MAXN];

using namespace std;

int cap[MAXN][MAXN];
int flow[MAXN][MAXN];

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

	
int main() {
    int n;
    while(scanf("%d", &n)!=EOF){
    	memset(cap, 0, sizeof cap);
    	memset(flow, 0, sizeof flow);
    	for (int i = 1; i <= n; ++i){
    		int tmp;
    		scanf("%d", &tmp);
    		cap[i][n+i] = tmp;
    	}
    	int c;
    	scanf("%d", &c);
    	for(int i = 0; i < c; ++i){
    		int l, r, d;
    		scanf("%d%d%d", &l, &r, &d);
    		cap[l+n][r] = d;
    	}
    	const int s = 2*n + 1;
    	const int t = 2*n + 2;
    	int b, d;
    	scanf("%d%d", &b, &d);
    	for (int i = 0; i < b; ++i){
    		int tmp;
    		scanf("%d", &tmp);
    		cap[s][tmp] = INF;
    	}
    	for (int i = 0; i < d; ++i){
    		int tmp;
    		scanf("%d", &tmp);
    		cap[tmp+n][t] = INF;
    	}
    	int ans = FordFulkerson(s, t, t);
    	printf("%d\n", ans);
    }
    return 0;
}
