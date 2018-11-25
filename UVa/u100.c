#include <stdio.h>
#define SWAP(x, y) (x=x+y, y=x-y, x=x-y) 

int uva100(int n){
	int term = 1;

	for(; n != 1; term++)
		n = (n % 2 == 1) ? 3*n + 1 : n/2;

	return term;
}

int main(){
	int a, b, n, temp;
	int max;

	while(scanf("%d %d", &a, &b) != EOF){
		int temp_a = a;
		int temp_b = b;

		if(a > b)
			SWAP(a, b);
		max = 0;
		for(n = a; n <= b; n++){
			temp = uva100(n);
			max = max > temp ? max : temp;
		}
		printf("%d %d %d\n", temp_a, temp_b, max);

}
	return 0;
}