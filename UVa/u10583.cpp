#include <cstdio>
int p[50001];
bool max[50001];
int Find(int x){
	if(x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b){
	int A = Find(a);
	int B = Find(b);
	p[A] = B;
}

int main(){
	int n, m;
	int round = 0;
	while(scanf("%d %d", &n, &m) && !(n == 0 && m == 0)){
		for (int i = 1; i <= n; ++i){
			p[i] = i;
			max[i] = false;
		}
		while(m--){
			int a, b;
			scanf("%d %d", &a, &b);
			Union(a, b);
		}
		for (int i = 1; i <= n; ++i)
			max[Find(i)] = true;
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if(max[i] == true)
				sum++;
		printf("Case %d: %d", ++round, sum);
	}
	return 0;
}