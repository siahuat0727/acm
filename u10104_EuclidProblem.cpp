#include <cstdio>

int exGCD(int a, int b, int &X, int &Y){
	if(b == 0){
		X = 1;
		Y = 0;
		return a;
	}else{
		int gcd = exGCD(b, a%b, X, Y);
		int tmp = X;
		X = Y;
		Y = tmp - (a/b)*Y;
		return gcd;
	}
}

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		int X, Y;
		int D = exGCD(a, b, X, Y);
		printf("%d %d %d\n", X, Y, D);
	}
	return 0;
}