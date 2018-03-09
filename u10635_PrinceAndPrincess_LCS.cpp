#include <cstdio>
// TLE
int main(){
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case){
		int n, p, q;
		scanf("%d %d %d", &n, &p, &q);
		++p;
		++q;
		unsigned short LCS[p+1][q+1];
		unsigned short Ap[p];
		unsigned short Aq[q];
		for (int j = 0; j < p; ++j)
			scanf("%d", &Ap[j]);
		for (int j = 0; j < q; ++j)
			scanf("%d", &Aq[j]);
		for (int j = 0; j <= p; ++j)
			LCS[j][0] = 0;
		for (int j = 1; j <= q; ++j)
			LCS[0][j] = 0;
		for (int i = 1; i <= p; ++i){
			for (int j = 1; j <= q; ++j){
				// if(i == 1 && j == 1)
				// 	printf("%d %d %d\n", LCS[0][0], Ap[0], Aq[0]);
				if(Ap[i-1] == Aq[j-1]){
					LCS[i][j] = LCS[i-1][j-1] + 1;
				}else if(LCS[i-1][j] >= LCS[i][j-1]){
					LCS[i][j] = LCS[i-1][j];
				}else{
					LCS[i][j] = LCS[i][j-1];
				}
			}
		}
		// for (int i = 0; i <= p; ++i){
		// 	for (int j = 0; j <= q; ++j){
		// 		printf("%d ", LCS[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		printf("Case %d: %d\n", Case, LCS[p][q]);
	}
	return 0;
}