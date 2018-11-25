#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 9
void print_monomial(int coe[N], int i){
	if(i != 0){
		if(abs(coe[i]) != 1)
			printf("%d", coe[i]);
		printf("x");
		if(i != 1)
			printf("^%d", i);
	}else
		printf("%d", coe[i]);
}

int main(){
	int coe[N];
	while(scanf("%d", &coe[N-1]) != EOF){
		for (int i = N-2; i >= 0; --i){
			scanf("%d", &coe[i]);
		}
		bool first = true;
		for (int i = N-1; i >= 0; --i){
			if(coe[i] != 0){
				if(first){
					printf("%s", coe[i] < 0 ? "-" : "");
					coe[i] = abs(coe[i]);
					print_monomial(coe, i);
					first = false;
				}else{
					printf("%s", coe[i] < 0 ? " - " : " + ");
					coe[i] = abs(coe[i]);
					print_monomial(coe, i);
				}
			}
		}
		if(first)
			printf("0");
		printf("\n");
	}
	return 0;
}