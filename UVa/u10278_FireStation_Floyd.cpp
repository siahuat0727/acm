#include <cstdio>
#include <cstring>
#define MAXN 505
#define INF 100000000
int dis[MAXN][MAXN];
int F[105];
void Floyd_init(int numV){
	for (int i = 1; i <= numV; ++i){ // index start from 0
		for (int j = 1; j <= numV; ++j){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
}

void Floyd(int numV){
	for (int k = 1; k <= numV; ++k) // index start from 0
		for (int i = 1; i <= numV; ++i)
			for (int j = 1; j <= numV; ++j)
				if(dis[i][k]+dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
}

bool existInF(int n, int f){
	for (int i = 0; i < f; ++i)
		if(n == F[i])
			return true;
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int f, I;
		scanf("%d%d", &f, &I);
		Floyd_init(I);
		for (int i = 0; i < f; ++i){
			int t;
			scanf("%d", &t);
			F[i] = t;
		}
		getchar();
		char str[50];
		while(gets(str)!=NULL && strlen(str)>>1){
			int l, r, d;
			sscanf(str, "%d%d%d", &l, &r, &d);
			dis[l][r] = dis[r][l] = d;
		}
		Floyd(I);
		int Min = INF;
		int Ans = 1;
		// for (int i = 1; i <= I; ++i){
		// 	for (int j = 1; j <= I; ++j){
		// 		printf("%d ", dis[i][j]);
		// 	}
		// 	puts("");
		// }
		for (int k = 1; k <= I; ++k){
			// if(existInF(k, f))
			// 	continue;
			int mMax = 0;
			for (int j = 1; j <= I; ++j){
				int mMin = INF;
				if(j == k || existInF(j, f))
					continue;
				for (int i = 0; i < f; ++i){
					// printf("%d %d %d\n", F[i], j, dis[F[i]][j]);
					if(dis[F[i]][j] < mMin){
						mMin = dis[F[i]][j];
					}
				}
				if(dis[k][j] < mMin){
					mMin = dis[k][j];
				}
				if(mMin > mMax)
					mMax = mMin;
			}
			if(mMax < Min){
				Min = mMax;
				Ans = k;
			}
			// printf("Min = %d\n", Min);
		}
		printf("%d\n", Ans);
		if(T)
			putchar('\n');
	}
	return 0;
}