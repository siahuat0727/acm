#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<long long int> prime;
bool isPrime(long long int n){
	for (int i = 0; prime[i]*prime[i] <= n; ++i)
		if(n % prime[i] == 0)
			return false;
	return true;
}

int main(){
	long long int Max = 1000000;
	prime.push_back(2);
	prime.push_back(3);
	int primeNum = 2;
	for (int i = 5, gap = 2; i < Max; i += gap, gap = 6-gap){
		if(isPrime(i)){
			++primeNum;
			prime.push_back(i);
		}
	}
	long long int n;
	while(scanf("%lld", &n) && n != -1){
		int i = 0;
		while(n != 1){
			if(i >= primeNum){
				// printf("    ");
				printf("    %lld\n", n);
				break;
			}
			if(n % prime[i] == 0){
				// printf("    ");
				printf("    %d\n", prime[i]);
				n /= prime[i];
			}
			else
				++i;
		}
		puts("");
	}
	return 0;
}
