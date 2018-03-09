#include <cstdio>

int gcd(int a, int b){
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		printf("%10d%10d    %s\n\n", a, b, gcd(a, b) == 1 ? "Good Choice" : "Bad Choice");
	}
	return 0;
}