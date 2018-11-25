#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
// #define INF 5000001
#define INF 999999999
#define MAXN 20005
struct path{
	int r;
	int latency;
};
int dis[MAXN];
// int p[MAXN][MAXN];
vector<path> Vp[MAXN];
int count[MAXN];
bool inqueue[MAXN];
// void SPFA_init(int n){
// 	for (int i = 0; i < n; ++i)
// 		for (int j = 0 ;j < n; ++j)
// 			p[i][j] = INF;	
// }

bool SPFA(int n, int source){ // remenber to clear Vp after each case 
	for (int i = 0; i < n; ++i){
		dis[i] = INF;
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
		for (int i = 0; i < Vp[now].size(); ++i){
			int r = Vp[now][i].r;
			int d = Vp[now][i].latency;
			if(dis[now] + d < dis[r]){
				dis[r] = dis[now] + d;
				if(!inqueue[r]){
					Q.push(r);
					inqueue[r] = true;
					count[r]++;
					if(count[r] >= n)
						return true;
				}
			}
		}
	}
	return false;
}

void solve(){
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	// SPFA_init(n);
	for (int i = 0; i < MAXN; ++i)
		Vp[i].clear();
	for (int i = 0; i < m; ++i){
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		path p1 = {r, d};
		path p2 = {l, d};
		Vp[l].push_back(p1);
		Vp[r].push_back(p2);
	}
	SPFA(n, s);
	if(dis[t] == INF)
		printf("unreachable\n");
	else
		printf("%d\n", dis[t]);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}