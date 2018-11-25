#include <cstdio>
#include <cmath>

#define EPS 1e-13

bool check(int c, int d, double rational, double n){
	double diff = (double)c/d - rational;
	if (diff > EPS && diff - n < EPS && diff != 0)
		return true;
	return false;
}

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		double n;
		scanf("%lf", &n);
		int d = 0;
		int c;
		double rational = (double)a/b;
		while(1){
			if(++d == b)
				continue;
			c = ceil(d*rational);
			if(check(c, d, rational, n))
				break;
			if(check(++c, d, rational, n))
				break;
		}
		printf("%d %d\n", c, d);
	}
	return 0;
}
