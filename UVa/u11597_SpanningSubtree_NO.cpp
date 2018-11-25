#include <cstdio>

int main(){
	int T = 0, n;
	while(scanf("%d", &n) && n)
		printf("Case %d: %d\n", ++T, n >> 1);
}