#include <cstdio>
#define CHOOSE_TWO(n) ((long long int)(n)*((n)-1)/2)

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) && !(a == 0 && b == 0)){
		const int Max =  a > b ? a : b;
		const int Min = a + b - Max;

		const int diff = Max - Min;
		long long int sub_ways = 0;
		for (int i = Min-1; i >= 2; --i)
			sub_ways += CHOOSE_TWO(i);
		// 方程式的多项式依次是 横的 直的 最长的斜的 旁边两边的斜的
		// 希望以后看得懂自己写什么=.=
		long long int ways = 2*(a*CHOOSE_TWO(b) + b*CHOOSE_TWO(a) + 2*((diff+1)*CHOOSE_TWO(Min) + 2*sub_ways));
		// printf("%lld %lld %lld %lld\n", a*CHOOSE_TWO(b), b*CHOOSE_TWO(a), (diff+1)*CHOOSE_TWO(Min), sub_ways);
		printf("%lld\n", ways);		
	}
	return 0;
}