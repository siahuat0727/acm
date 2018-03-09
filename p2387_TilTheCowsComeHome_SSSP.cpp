#include <cstdio>
#define INF 1000000000
struct edge{
	int l;
	int r;
	int d;
};

int main(){
	int T, N;
	scanf("%d %d", &T, &N);
	edge E[2005];
	for (int i = 0; i < T; ++i)
		scanf("%d %d %d", &E[i].l, &E[i].r, &E[i].d);
	int dis[1005];
	for (int i = 1; i < N; ++i)
		dis[i] = INF;
	dis[N] = 0;
	for (int term = 0; term < N-1; ++term){
		bool change = false;
		for (int i = 0; i < T; ++i){
			const int left = E[i].l;
			const int right = E[i].r;
			const int length = E[i].d;
			if(dis[left] > dis[right] + length){
				dis[left] = dis[right] + length;
				change = true;
			}else if(dis[right] > dis[left] + length){
				dis[right] = dis[left] + length;
				change = true;
			}
		}
		if(!change)
			break;
	}
	printf("%d\n", dis[1]);
	return 0;
}