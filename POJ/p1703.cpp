#include <cstdio>

int same[200005];

int Find(int a){
	return a == same[a] ? a : same[a] = Find(same[a]);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d%*c", &n, &m);
		for (int i = 1; i <= 2*n; ++i)
			same[i] = i;
		while(m--){
			char c;
			int a, b;
			scanf("%c%d%d%*c", &c, &a, &b);
			int aDiff = Find(a+n);
			int bDiff = Find(b+n);
			a = Find(a);
			b = Find(b);
			if(c == 'D'){
				same[a] = bDiff;
				same[b] = aDiff;
			}else
				printf("%s\n", a == b ? "In the same gang." : a == bDiff ? "In different gangs." : "Not sure yet.");
			}
	}
	return 0;
}