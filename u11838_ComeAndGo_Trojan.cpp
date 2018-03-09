#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define MAXN 2001
vector<int> Vp[MAXN];
bool instack[MAXN];
int dfn[MAXN];
int low[MAXN];
int index;
int count;
stack<int> S;

void Trojan(int cur){
	int child = 0;
	dfn[cur] = low[cur] = ++index;
	instack[cur] = true;
	S.push(cur);

	// bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(dfn[next] == 0){
			// child++;
			Trojan(next);
			if(low[next] < low[cur])
				low[cur] = low[next];
			// if(dfn[cur] <= low[next]) // 若能到ancestors,low会较小
			// 	cutv = true; // 表示不能到ancestors， 是cut-vertex
		}else if(instack[next] && dfn[next] < low[cur])
			low[cur] = dfn[next];
	}
	if(dfn[cur] == low[cur]){
		count++;
		int next;
		do{
			next = S.top();
			S.pop();
			instack[next] = false;
			// belong[next]=count;
		}while(next!=cur);
	}
	// if((~parent && cutv )|| (!~parent && child >= 2)){
	// 	// printf("qq %d\n", cur);
	// 	++crit;
	// }
}

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) && (n || m)){
		for (int i = 1; i <= n; ++i){
			Vp[i].clear();
			count = 0;
			dfn[i] = low[i] = 0;
		}
		index = 0;
		for (int i = 0; i < m; ++i){
			int l, r, way;
			scanf("%d%d%d", &l, &r, &way);
			Vp[l].push_back(r);\
			if(way == 2){
				Vp[r].push_back(l);
			}
		}
		for(int i = 1; i <=n ; ++i){
			if(dfn[i] == 0){
				// printf("qq\n");
				Trojan(i);
			}
		}
		printf("%d\n", count == 1 ? 1 : 0);
	}
	return 0;
}