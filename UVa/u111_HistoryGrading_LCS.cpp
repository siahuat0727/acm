#include <cstdio>
int N;
using namespace std;

int main(){
	scanf("%d", &N);
	int ans[N+2];
	int arr[N+2];
	int LCS[N+2][N+2];
	int t;
	for (int i = 1; i <= N; ++i){
		scanf("%d", &t);
		ans[t] = i;
	}
	while(scanf("%d", &t) != EOF){
		arr[t] = 1;
		for (int i = 2; i <= N; ++i){
			scanf("%d", &t);
			arr[t] = i;
		}
		for (int i = 0; i <= N; ++i){
			LCS[0][i] = LCS[i][0] = 0;
		}
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j){
				if(ans[i] == arr[j]){
					LCS[i][j] = LCS[i-1][j-1] + 1;
				}else{
					if(LCS[i-1][j] >= LCS[i][j-1]){
						LCS[i][j] = LCS[i-1][j];
					}else{
						LCS[i][j] = LCS[i][j-1];
					}
				}
			}
		}
		printf("%d\n", LCS[N][N]);
	}
	return 0;
}