#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
#define INF 1000000000
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];

using namespace std;

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
		if(cap[pre][i]-flow[pre][i]>0)
			f = min(f, cap[pre][i]-flow[pre][i]);
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
    int T = 0;
    while(scanf("%d", &n) && n){
    	++T;
    	int s, t, c;
    	scanf("%d%d%d", &s, &t, &c);
    	memset(cap, 0, sizeof cap);
    	memset(flow, 0, sizeof flow);
    	for(int i = 0; i < c; ++i){
    		int l, r, d;
    		scanf("%d%d%d", &l, &r, &d);
    		cap[l][r] += d;
    		cap[r][l] += d;
    	}
    	int ans = FordFulkerson(s, t, c);
    	printf("Network %d\n", T);
    	printf("The bandwidth is %d.\n", ans);
    	printf("\n");
    }
    return 0;
}
