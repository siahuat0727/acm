#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define MAXN 102
int dfn[MAXN];
int low[MAXN];
int Index;
vector<int> Vp[MAXN];
vector<string> Vans;
map<string, int> M;
void Artic_dfs(int cur, int parent){
	int child = 0;
	dfn[cur] = low[cur] = ++Index;

	bool cutv = false; // 只要有一圈不能到ancestors就会是cutv
	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(dfn[next] == 0){
			child++;
			Artic_dfs(next, cur);
			low[cur] = min(low[cur], low[next]);

			if(dfn[cur] <= low[next]){ // 若能到ancestors,low会较小 | < for bridge
				cutv = true; // 表示不能到ancestors， 是cut-vertex
			}

		}else if(next == parent)
			continue;
		else
			low[cur] = min(low[cur], dfn[next]);
	}
	if((~parent && cutv )|| (!~parent && child >= 2)){
		// printf("qq %d\n", cur);
		for(auto it = M.begin(); it != M.end(); ++it){
			if(it->second == cur){
				Vans.push_back(it->first);
				break;
			}
		}
	}
}

int main(){
	int T;
	int Case = 0;
	while(scanf("%d", &T) && T){
		if(Case)
			puts("");
		Case++;
		Vans.clear();
		M.clear();
		Index = 0;
		for (int i = 1; i <= T; ++i){
			char str[31];
			cin >> str;
			M[str] = i;
			Vp[i].clear();
			dfn[i] = 0;
		}
		int N;
		scanf("%d", &N);
		while(N--){
			char str1[31], str2[31];
			cin >> str1 >> str2;
			int n1 = M[str1];
			int n2 = M[str2];
			Vp[n1].push_back(n2);
			Vp[n2].push_back(n1);
		}
		for(int i = 1; i <= T; ++i){
			if(!dfn[i])
				Artic_dfs(i, -1);
		}
		sort(Vans.begin(), Vans.end());
		printf("City map #%d: %d camera(s) found\n", Case, Vans.size());
		while(!Vans.empty()){
			cout << Vans[0] << endl;
			Vans.erase(Vans.begin());
		}
	}
	return 0;
}