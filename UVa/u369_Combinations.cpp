#include <stdio.h>
#define PRINT(n) (printf(#n" = %d\t", (n)))

unsigned long long product_through(int a, int b){
	// check for n == m
	unsigned long long answer = 1;
	if(a <= b){
		for (int i = a; i <= b; ++i)
			answer *= i;
	}
	return answer;
}

unsigned long long factorial(int n){
	unsigned long long answer = 1;
	for (int i = 1; i <= n; ++i)
		answer *= i;
	return answer;
}


int main(){
	// printf("%d\n", (int)product_through(1, 5));
	while(1){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;
		const int larger = n-m > m ? n-m : m;
		const int smaller = n-m < m ? n-m : m;
		PRINT(larger);
		PRINT(smaller);
		PRINT((int)product_through(n-larger, n));
		PRINT((int)factorial(smaller));
		printf("%d things taken %d at a time is %d exactly.\n", n, m, (int)(product_through(larger+1, n)/factorial(smaller)));
	}
	return 0;
}