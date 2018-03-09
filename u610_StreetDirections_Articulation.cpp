#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAXN 2001
vector<int> Vp[MAXN];
bool instack[MAXN];
int dfn[MAXN];
int low[MAXN];
int belong[MAXN];
int index;
int Count;
stack<int> S;

struct road
{
	int l, r;
};

vector<road> Vans;
void Artic_dfs(int cur, int parent){
	int child = 0;
	dfn[cur] = low[cur] = ++index;

	bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(dfn[next] == 0){
			printf("%d %d\n", cur, next);
			child++;
			Artic_dfs(next, cur);
			low[cur] = min(low[cur], low[next]);

			if(dfn[cur] < low[next]){ // 若能到ancestors,low会较小
				printf("%d %d\n", next, cur);
				cutv = true; // 表示不能到ancestors， 是cut-vertex
			}

		}else if(next == parent)
			continue;
		else{
			if(dfn[cur] >= dfn[next])
				printf("%d %d\n", cur, next);
			low[cur] = min(low[cur], dfn[next]);
		}
	}
	if((~parent && cutv )|| (!~parent && child >= 2)){
		// ++crit;
	}
}

int main(){
	int n, m;
	int T = 1;
	while(scanf("%d%d", &n, &m) && (n || m)){
		for(int i = 1; i <= n; ++i){
			Vp[i].clear();
			instack[i] = false;
			dfn[i] = 0;
			low[i] = 0;
			//belong[i] = 0;
			Count = 0;
		}
		for(int i = 1; i <= m; ++i){
			int l, r;
			scanf("%d%d", &l, &r);
			Vp[l].push_back(r);
			Vp[r].push_back(l);
		}
		printf("%d\n\n", T++);
		for(int i = 1; i <= n; ++i){
			if(!dfn[i]){
				Artic_dfs(i, -1);
			}
		}
		// for(int i = 1; i <= n; ++i){
		// 	while(!Vp[i].empty()){
		// 		printf("%d %d\n", i, Vp[i]);
		// 		Vp[i].erase(Vp[i].begin());
		// 	}
		// }
		printf("#\n");
	}
}

// void Trojan(int cur){
// 	int child = 0;
// 	dfn[cur] = low[cur] = ++index;
// 	instack[cur] = true;
// 	S.push(cur);

// 	// bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
// 	int size = Vp[cur].size();
// 	for (int i = 0; i < size; ++i){
// 		int next = Vp[cur][i];
// 		if(dfn[next] == 0){
// 			// child++;
// 			Trojan(next);
// 			if(low[next] < low[cur])
// 				low[cur] = low[next];
// 			// if(dfn[cur] <= low[next]) // 若能到ancestors,low会较小
// 			// 	cutv = true; // 表示不能到ancestors， 是cut-vertex
// 		}else if(instack[next] && dfn[next] < low[cur])
// 			low[cur] = dfn[next];
// 	}
// 	if(dfn[cur] == low[cur]){
// 		Count++;
// 		int next;
// 		int last = cur;
// 		do{
// 			next = S.top();
// 			printf("%d %d\n", last,next);
// 			Vp[last].erase(find(Vp[last].begin(), Vp[last].end(), next));
// 			Vp[next].erase(find(Vp[next].begin(), Vp[next].end(), last));
// 			// road ro = {last, next};
// 			// Vans.push_back(ro);
// 			S.pop();
// 			instack[next] = false;
// 			// belong[next] = last;
// 			last = next;
// 		}while(next!=cur);
// 	}
// 	// if((~parent && cutv )|| (!~parent && child >= 2)){
// 	// 	// printf("qq %d\n", cur);
// 	// 	++crit;
// 	// }
// }