#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 101

vector<int> Vp[MAXN];
int dfn[MAXN];
int low[MAXN];
int index;
int crit;

void Artic_dfs(int cur, int parent){
	int child = 0;
	dfn[cur] = low[cur] = ++index;

	bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(dfn[next] == 0){
			child++;
			Artic_dfs(next, cur);
			if(low[next] < low[cur])
				low[cur] = low[next];
			if(dfn[cur] <= low[next]) // 若能到ancestors,low会较小
				cutv = true; // 表示不能到ancestors， 是cut-vertex
		}else if(next != parent && dfn[next] < low[cur])
			low[cur] = dfn[next];
	}
	if((~parent && cutv )|| (!~parent && child >= 2)){
		// printf("qq %d\n", cur);
		++crit;
	}
}

int main(){
	int N;
	while(scanf("%d", &N) && N){
		crit = index = 0;
		for (int i = 1; i <= N; ++i){
			Vp[i].clear();
			dfn[i] = low[i] = 0;
		}
		int s;
		while(scanf("%d", &s) && s){
			while(getchar() == ' '){
				int e;
				scanf("%d", &e);
				Vp[s].push_back(e);
				Vp[e].push_back(s);
			}
		}
		Artic_dfs(1, -1);
		printf("%d\n", crit);
	}
	return 0;
}