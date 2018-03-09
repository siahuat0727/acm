#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int t;
		scanf("%d", &t);
		int l = lower_bound(a, a+N, t) - a;
		int u = lower_bound(a+l, a+N, t+1) - (a+l);
		u += l; // try to get 0.000s but failed=.=
		if(l <= 0)
			putchar('X');
		else
			printf("%d", a[l-1]);
		putchar(' ');
		if(u >= N)
			putchar('X');
		else
			printf("%d", a[u]);
		putchar('\n');
	}
	return 0;
}