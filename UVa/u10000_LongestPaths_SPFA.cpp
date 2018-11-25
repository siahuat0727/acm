#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 105

// struct edge{
// 	int l, r, d;
// }E[MAXN];
int dis[MAXN];
bool inqueue[MAXN];
bool p[MAXN][MAXN];
int count[MAXN];
// n = numV, 有负环return true, 可知道负环经过sourse,觉得有没有经过都要知道可以一开始push全部进去
bool SPFA(int n, int source){ 
	for (int i = 1; i <= n; ++i){
		dis[i] = 0;
		inqueue[i] = false;
		count[i] = 0;
	}
	dis[source] = 0;
	inqueue[source] = true;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty()){
		int now = Q.front();
		inqueue[now] = false;
		Q.pop();
		for (int i = 1; i <= n; ++i){
			if(p[now][i] && dis[now] + p[now][i] > dis[i]){
				// printf("qq\n");
				dis[i] = dis[now] + p[now][i];
				if(!inqueue[i]){
					Q.push(i);
					inqueue[i] = true;
					count[i]++;
					if(count[i] >= n)
						return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int T = 0;
	int s, n;
	int index = 0;
	while(scanf("%d", &n) && n){
		scanf("%d", &s);
		int l, r;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n; ++j)
				p[i][j] = false;
		while(scanf("%d%d", &l, &r) && !(l == 0 && r == 0)){
			index++;
			p[l][r] = true;
			// E[index].l = l;
			// E[index].r = r;
			// E[index++].d = 1;
		}
		SPFA(n, s);
		++T;
		int Max = dis[1], MaxId = 1;
		for (int i = 2; i <= n; ++i){
			if(dis[i] > Max){
				Max = dis[i];
				MaxId = i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", T, s, Max, MaxId);
	}
	return 0;
}