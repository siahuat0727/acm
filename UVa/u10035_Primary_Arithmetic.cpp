#include <cstdio>

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) && !(a == 0 && b == 0)){
		bool carry = false;
		int num_carry = 0;
		for (int i = 0; i < 10; ++i){
			const int tmp = a % 10 + b % 10 + carry;
			a /= 10;
			b /= 10;
			carry = false;
			if(tmp >= 10){
				carry = true;
				++num_carry;
			}
		}
		if(num_carry)
			printf("%d", num_carry);
		else
			printf("No");
		printf(" carry operation");
		if(num_carry == 0 || num_carry == 1)
			puts(".");
		else
			puts("s.");
	}
	return 0;
}