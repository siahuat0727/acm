#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 505
struct Dot{
	double x, y;
};

struct Len{
	int id1, id2;
	double length;
}L;

vector<Len> V;
vector<double> Vans;
Dot D[MAXN];
int p[MAXN];



int Find(int x){
	// printf("find qq %d = p %d\n", x, p[x]);
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

bool cmp(Len a, Len b){
	return a.length < b.length;
}

void Kruskal(int n){
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
		Vans.push_back(l.length);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int s, P;
		scanf("%d%d", &s, &P);
		V.clear();
		Vans.clear();
		memset(D, 0, sizeof D);
		int total_edge = 0;
		for (int i = 0; i < P; ++i){
			p[i] = i;
			double a, b;
			scanf("%lf%lf", &a, &b);
			Dot d = {a, b};
			D[i] = d;
			for(int j = 0; j < i; ++j){
				double x_diff = D[i].x - D[j].x;
				double y_diff = D[i].y - D[j].y;
				Len l = {i, j, sqrt(x_diff*x_diff + y_diff*y_diff)};
				V.push_back(l);
				// printf("main qq %d %d %lf\n", l.id1, l.id2, l.length);
				total_edge++;
			}
		}
		sort(V.begin(), V.end(), cmp);
		Kruskal(P-s+1);
		printf("%.2lf\n", Vans[P-s-1]);
	}
}