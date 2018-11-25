#include <cstdio>
#define MAXN 1001
#define INF 2001*MAXN
struct edge{
	int l;
	int r;
	int d;
}E[2001];
int dis[MAXN];

// num = # of V, n = # of E, false means no negative cycle, V index start from 0
bool SSSP(int num, int n){ 
	for (int i = 0; i < num; ++i)
		dis[i] = INF;
	dis[0] = 0;
	for (int term = 0; term < num; ++term){//num-1+1
		// for (int i = 0; i < num; ++i)
		// 	printf("%d ", dis[i]);
		// printf("\n");
		bool change = false;
		for (int i = 0; i < n; ++i){
			const int left = E[i].l;
			const int right = E[i].r;
			const int length = E[i].d;
			if(dis[right] > dis[left] + length){
				dis[right] = dis[left] + length;
				change = true;
			}
		}
		if(!change)
			return false;
	}
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i){
			int l, r, t;
			scanf("%d%d%d", &l, &r, &t);
			E[i].l = l;
			E[i].r = r;
			E[i].d = t;
		}
		printf("%s\n", SSSP(n, m) ? "possible" : "not possible");
	}

	return 0;
}
