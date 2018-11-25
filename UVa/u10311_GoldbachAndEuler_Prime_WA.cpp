#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 100000005

bool isPrime[MAXN];

void eratosthenes(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrt_max = sqrt(MAXN);
	for(int i = 2; i <= sqrt_max; ++i)
		//printf("for %d\n", i);
		if(isPrime[i])
			for(int j = i*i; j < MAXN; j += i)
				isPrime[j] = false;
}

int main(){
	eratosthenes();
	int n;
	while(scanf("%d", &n) != EOF){
		bool succ = false;
		int i;
		for(i = n>>1; i >= 2; --i){
			if(isPrime[i] && isPrime[n-1]){
				succ = true;
				break;
			}
		}
		if(succ)
			printf("%d is the sum of %d and %d.\n", n, i, n-i);
		else
			printf("%d is not the sum of two primes!\n", n);
	}
	return 0;
}
