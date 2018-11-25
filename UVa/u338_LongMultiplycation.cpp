#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define LENGTH(n) ((n) == 0 ? 1 : (int)log10(n) + 1)

#define LENGTH_ARR(n, L) 			\
	do{								\
		L = 20;						\
		while(!n[--L] && L != 0);	\
		++L;						\
	}while(0)

#define PRINT_NUM(x, n) 						\
	do{											\
		const int xLength = LENGTH(x);			\
		for (int j = 0; j < n-xLength; ++j)		\
			printf(" ");						\
		printf("%llu\n", x);					\
	}while(0)							

#define PRINT_ARR(ans, L, n)					\
	do{											\
		for (int i = 0; i < n - L; ++i)			\
			printf(" ");						\
		for (int i = L - 1; i >= 0; --i)		\
			printf("%d", ans[i]);				\
		printf("\n");							\
	}while(0)

void multiply(unsigned long long int a, unsigned long long int b, unsigned long long int ans[]){
	if(a == 0 || b == 0)
		return;
	for (int i = 0; i < 20-1; ++i, b/=10){
		ans[i] += (b % 10)*a;
		ans[i + 1] = ans[i] / 10;
		ans[i] -= ans[i+1]*10;
	}
}

int main(){
	char str[200];
	while(gets(str) && str[1]){
		char cstr1[100], cstr2[100];
		sscanf(str, "%s%s", cstr1, cstr2);
		// printf("%s %s\n", cstr1, cstr2);
		string str1(cstr1), str2(cstr2);
		while(str1.length()>1 && str1[0] == '0')
			str1 = str1.substr(1);
		while(str2.length()>1 && str2[0] == '0')
			str2 = str2.substr(1);
		unsigned long long int a, b;
		a = stoull(str1);
		b = stoull(str2);

		printf("%llu %llu\n", a, b);
		unsigned long long int ans[20] = {0};
		multiply(a, b, ans);
		int ansLength;
		LENGTH_ARR(ans, ansLength);
		const int aLength = LENGTH(a);
		const int bLength = LENGTH(b);
		const int Max = MAX(aLength, bLength);
		const int maxLength = MAX(Max, ansLength);

		PRINT_NUM(a, maxLength);
		PRINT_NUM(b, maxLength);
		for (int i = 0; i < ansLength - Max; ++i)
			printf(" ");
		for (int i = 0; i < Max; ++i)
			printf("-");
		printf("\n");


		int totalLine = 0;
		if(a != 0 && b != 0){
			int bZero = 0;
			for (int i = 0; i < bLength; ++i){
				int bDigit = b % 10;
				if(bDigit == 0)
					++bZero;
				else{
					while(totalLine == 0 && i == bLength - 1 && bZero != 0 && bZero--)
						bDigit *= 10;
					const unsigned long long int tmp = bDigit * a;
					PRINT_NUM(tmp, ansLength - i);
					++totalLine;
				}
				b /= 10;
			}
			// if(bZero != 0){
			// 	printf("0\n");
			// }
		}else{
			PRINT_NUM(0, maxLength);
		}
		if(totalLine > 1){
			for (int i = 0; i < ansLength; ++i)
				printf("-");
			printf("\n");
			PRINT_ARR(ans, ansLength, maxLength);
		}
		printf("\n");
	}
	return 0;
}