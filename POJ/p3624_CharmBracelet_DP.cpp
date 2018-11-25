#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	int dp[12900] = {0};
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		for (int j = M-n; j >= 0;  --j)
			dp[j+n] = max(dp[j+n], dp[j] + m);
	}
	printf("%d\n", dp[M]);
	return 0;
}