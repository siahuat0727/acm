#include <cstdio>
#define MAXN 5250
#define INF 10001*MAXN

struct edge{
	int l;
	int r;
	int d;
}E[MAXN];
int dis[MAXN];

bool SSSP(int num, int n){
	for (int i = 0; i < num; ++i)
		dis[i] = INF;
	dis[0] = 0;
	for (int term = 0; term < n; ++term){//n-1+1
		bool change = false;
		for (int i = 0; i < num; ++i){
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
	int F;
	scanf("%d", &F);
	while(F--){
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		int index = 0;
		for (int i = 0; i < m; ++i){
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			E[index].l = s;
			E[index].r = e;
			E[index++].d = t;
			E[index].l = e;
			E[index].r = s;
			E[index++].d = t;
		}
		for (int i = 0; i < w; ++i){
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			E[index].l = s;
			E[index].r = e;
			E[index++].d = -t;
		}
		printf("%s\n", SSSP(index, n) ? "YES": "NO");
	}
	return 0;
}