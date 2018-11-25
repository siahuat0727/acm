#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Coin{
	int d, v;
};

int main(){
	int t, w;
	bool first = true;
	while(scanf("%d %d", &t, &w) != EOF){
		if(first)
			first = false;
		else
			putchar('\n');
		int tt = (t/w)/3;
		int N;
		scanf("%d", &N);
		int dp[350] = {0};
		queue<Coin> Q[350]; //应该有更好的做法……
		for (int i = 0; i < N; ++i){
			int d, v;
			scanf("%d %d", &d, &v);
			for (int j = tt-d; j >= 0;  --j)
				if(dp[j] + v > dp[j+d]){
					dp[j+d] = dp[j] + v;
					Coin c = {d, v};
					Q[j+d] = Q[j];
					Q[j+d].push(c);
				}
		}
		printf("%d\n", dp[tt]);
		printf("%d\n", Q[tt].size());
		while(!Q[tt].empty()){
			Coin c = Q[tt].front();
			Q[tt].pop();
			printf("%d %d\n", c.d, c.v);
		}
	}
	return 0;
}