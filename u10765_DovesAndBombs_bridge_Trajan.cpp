#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
#define MAXN 10010
struct vecNum
{
	int vec, num;
};
vector<vecNum> Vans;
int dfn[MAXN];
int low[MAXN];
vector<int> Vp[MAXN];
int A[MAXN];
int Index;
bool cmp(vecNum a, vecNum b){
	return a.num == b.num ? a.vec < b.vec : a.num > b.num;
}

void Artic_dfs(int cur, int parent){
	// printf("qq %d\n", cur);
	int child = 0;
	dfn[cur] = low[cur] = ++Index;

	bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(dfn[next] == -1){
			child++;
			Artic_dfs(next, cur);
			low[cur] = min(low[cur], low[next]);

			if(dfn[cur] < low[next]){ // 若能到ancestors,low会较小 | < for bridge
				cutv = true; // 表示不能到ancestors， 是cut-vertex
				// printf("qq %d %d\n", cur, next);
				++A[cur];
				// ++A[next];
			}else if(dfn[cur] == low[next])
				 ++A[cur];

		}else if(next == parent)
			continue;
		else{
			low[cur] = min(low[cur], dfn[next]);
		}
	}
	if(parent == -1 && child < 2)
		A[cur] = 1;
	// if((~parent && cutv )|| (!~parent && child >= 2)){// find bridge no need to use this
		// printf("qq %d\n", cur);
	// }
}

int main(){
	int N, M;
	while(scanf("%d%d", &N, &M) && (N||M)){
		Index = 0;
		// Count = 0;
		Vans.clear();
		for(int i = 0; i < N; ++i){
			Vp[i].clear();
			dfn[i] = -1;
			A[i] = 1;
		}
		int vec, num;
		while(scanf("%d%d", &vec, &num) && (vec!= -1 && num != -1)){
			Vp[vec].push_back(num);
			Vp[num].push_back(vec);
		}
		// for(int i= 0; i < N; ++i){
		// 	if(dfn[i] == -1){
				Artic_dfs(0, -1);
		// 	}
		// }
		for(int i = 0; i < N; ++i){
			vecNum  v = {i, A[i]};
			Vans.push_back(v);
		}
		for(int i = 0; i < N; ++i){
			// printf("qq %d %d\n", dfn[i], low[i]);
		}
		sort(Vans.begin(), Vans.end(), cmp);
		for (int i = 0; i < M; ++i)
		{
			printf("%d %d\n", Vans[i].vec, Vans[i].num);
		}
		printf("\n");
	}
	return 0;
}
