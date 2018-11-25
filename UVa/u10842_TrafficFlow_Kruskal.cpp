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
	int length;
}L;

vector<Len> V;
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
	return a.length > b.length;
}

int Kruskal(int n){
	if(n == 0 || n == 1)
		return 0;
	int T = n-1;
	int ans = 0;
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
		ans = l.length;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	int Case = 0;
	while(T--){
		V.clear();
		memset(D, 0, sizeof D);
		int total_edge = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		while(m--){
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			if(l != r){
				Len len = {l, r, d};
				V.push_back(len);
			}
		}
		sort(V.begin(), V.end(), cmp);
		int Min = Kruskal(n);
		printf("Case #%d: %d\n", ++Case, Min);
	}
	return 0;
}