#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 105
#define INF 150000
int dis[MAXN][MAXN];

void Floyd_init(int numV){
	for (int i = 1; i <= numV; ++i){
		for (int j = 1; j <= numV; ++j){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
}

void Floyd(int numV){
	for (int k = 1; k <= numV; ++k)
		for (int i = 1; i <= numV; ++i)
			for (int j = 1; j <= numV; ++j)
				if(dis[i][j] > max(dis[i][k], dis[k][j]))
					dis[i][j] = max(dis[i][k], dis[k][j]);
}

int main(){
	int T = 0;
	int C, S, Q;
	while(scanf("%d %d %d", &C, &S, &Q) && !(C == 0 && S == 0 && Q == 0)){
		if(T)
			putchar('\n');
		++T;
		Floyd_init(C);
		while(S--){
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			dis[l][r] = dis[r][l] = d;
		}
		Floyd(C);
		printf("Case #%d\n", T);
		while(Q--){
			int l, r;
			scanf("%d%d", &l, &r);
			if(dis[l][r] == INF)
				printf("no path\n");
			else
				printf("%d\n", dis[l][r]);
		}
	}
	return 0;
}