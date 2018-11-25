#include <cstdio>

int main(){
	int m, n;
	while(scanf("%d %d", &m ,&n) != EOF){
		if(m > 1800)
			m += 200;
		int dp[10205] = {0};
		while(n--){
			int p, f;
			scanf("%d %d", &p, &f);
			if(p > m)
				continue;
			for (int i = m-p; i >= 0; --i){
				if(dp[i] + f > dp[i+p]){
					dp[i+p] = dp[i] + f;
				}
			}
		}
		int f = m;
		while(f > 0 && dp[f] == dp[f-1])
			--f;
		if(m > 2000 && f <= 2000) // 若
			printf("%d\n", dp[m-200]);
		else
			printf("%d\n", dp[m]);
	}
	return 0;
}