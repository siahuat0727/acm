#include <cstdio>

using namespace std;

typedef unsigned long long int ull;

int findHighestBit(ull k){
	int r = 0;
	while(k >>= 1)
		++r;
	return r;
}

ull n;

ull solve(ull k){
	if(k == 1)
		return n;
	int h = findHighestBit(k);
	if(k&(1ULL<<(h-1))){
		ull tmp = solve(k & ~(1ULL << h));
		return( (tmp >> 1) - !(tmp & 1));
	}else
		return solve(k-(1ULL<<(h-1)))>>1;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i){
		ull k;
		scanf("%llu %llu", &n, &k);
		ull ans = solve(k);
		ull n1 = (ans) >> 1;
		ull n2 = n1 - !(ans & 1);
		printf("Case #%d: %llu %llu\n", i, n1, n2);
	}
	return 0;
}