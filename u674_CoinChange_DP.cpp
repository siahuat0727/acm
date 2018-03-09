#include <cstdio>

int main(){
	int v[] = {1, 5, 10, 25, 50};
	int n;
	long long int dp[7550] = {0};
	dp[0] = 1;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 7490; ++j){
			dp[j+v[i]] += dp[j];
		}
	}
	while(scanf("%d", &n)!=EOF){
		printf("%lld\n", dp[n]);
	}
	return 0;
}