#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 755
struct Dot{
	int x, y;
};

struct Len{
	int id1, id2;
	double length;
}L;

vector<Len> V;
Dot D[MAXN];
int p[MAXN];



int Find(int x){
	// printf("find qq %d = p %d\n", x, p[x]);
	return x == p[x] ? x : p[x] = Find(p[x]);
}

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
	if(x != y)
		return true;
	else
		return false;
}

bool cmp(Len a, Len b){
	return a.length < b.length;
}

double Kruskal(int n){
	if(n == 0 || n == 1)
		return 0;
	int T = n-1;
	double ans = 0;
	int cur = 0;
	while(T--){
		// printf("qq T = %d\n", T);
		Len l;
		do{
			// printf("qq cur = %d\n", cur);
			l = V[cur++];
			// printf("qq cur = %d 1=%d 2=%d\n", cur, l.id1, l.id2);
		}while(Find(l.id1) == Find(l.id2));
		// printf("qq end while\n");
		Union(l.id1, l.id2);
		// printf("qq %lf\n", l.length);
		ans += l.length;
	}
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		V.clear();
		memset(D, 0, sizeof D);
		int total_edge = 0;
		for (int i = 1; i <= N; ++i){
			p[i] = i;
			int a, b;
			scanf("%d%d", &a, &b);
			Dot d = {a, b};
			D[i] = d;
			for(int j = 1; j < i; ++j){
				double x_diff = (double)D[i].x - D[j].x;
				double y_diff = (double)D[i].y - D[j].y;
				Len l = {i, j, sqrt(x_diff*x_diff + y_diff*y_diff)};
				V.push_back(l);
				// printf("main qq %d %d %lf %lf %lf %d %d\n", l.id1, l.id2, l.length, x_diff, y_diff, D[i].x, D[j].x);
				total_edge++;
			}
		}
		int M;
		scanf("%d", &M);
		int good = 0;
		for(int i = 0; i < M; ++i){
			int l, r;
			scanf("%d%d", &l, &r);
			if(Union(l, r))
					good++;
		}
		sort(V.begin(), V.end(), cmp);
		printf("%.2lf\n", Kruskal(N-good));

	}
	return 0;
}