#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-10
#define SOLVE(x) ((p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x)*(x) + u))
#define ROUND_FOUR(x) ((double)((int)(10000*(x)+eps))/10000)

int p, q, r, s, t, u;
double tmp;
double binary_search(double left, double right){
	double middle = ROUND_FOUR((left+right)/2);
	if(right - left < 0.00025){
		// printf("%f\n", (left+right)/2);
		// printf("%f %f %f\n", left, middle, right);
		double diffL = abs(SOLVE(left));
		double diffM = abs(SOLVE(middle));
		double diffR = abs(SOLVE(right));
		// printf("%f %f %f\n", diffL, diffM, diffR);
		return diffL <= diffM && diffL <= diffR ? left : diffM <= diffR ? middle : right;
	}
	// printf("qq left %f, right %f\n", left, right);
	while(left < right){
		double ans = ROUND_FOUR(SOLVE(middle));
		if(ans > 0)
			return binary_search(middle, right);
		else if(ans < 0)
			return binary_search(left,  middle);
		else
			return middle;
	}
	return right;
}



int main(){
	while(scanf("%d", &p) != EOF){
		scanf("%d %d %d %d %d", &q, &r, &s, &t, &u);
		double left = SOLVE(0);
		double right = SOLVE(1);
		if((left > 0 && right > 0) || (left < 0 && right < 0))
			printf("No solution\n");
		else
			printf("%.4f\n", binary_search(0, 1));
		// printf("%f\n", SOLVE(0.7071));
		// printf("%f\n", SOLVE(0.7072));
		// printf("%f\n", SOLVE(0.7073));
	}
}