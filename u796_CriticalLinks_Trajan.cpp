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
#define MAXN 1001
struct path
{
	int l, r;
};
int dfn[MAXN];
int low[MAXN];
bool instack[1001];
vector<int> Vp[MAXN];
vector<path> Vans;
stack<int> S;
int Count;
int Index;
bool cmp(path a, path b){
	return a.l == b.l ? a.r < b.r : a.l < b.l;
}

void Tarjan(int cur, int parent){
	dfn[cur] = low[cur] = ++Index;
	instack[cur] = true;
	S.push(cur);

	int size = Vp[cur].size();
	for (int i = 0; i < size; ++i){
		int next = Vp[cur][i];
		if(next == parent)
			continue;
		if(dfn[next] == -1){
			Tarjan(next, cur);
			if(low[next] < low[cur])
				low[cur] = low[next];
			if(low[next] > dfn[cur]){
				int l, r;
				l = next;
				r = cur;
				if(l > r){
					int t = l;
					l = r;
					r = t;
				}
				path p = {l, r};
				Vans.push_back(p);
			}
		}else if(dfn[next] < low[cur])
			low[cur] = dfn[next];
	}
}

int main(){
	int T;
	while(scanf("%d", &T) != EOF){
		Index = 0;
		Count = 0;
		Vans.clear();
		for (int t = 0; t < T; ++t){
			Vp[t].clear();
			dfn[t] = -1;
		}
		for(int i= 0; i < T; ++i){
			int t;
			cin >> t;
			int n;
			scanf(" (%d)", &n);
			while(n--){
				int tmp;
				cin >> tmp;
				Vp[t].push_back(tmp);
				// cout << tmp << endl;
			}
		}
		// for(int i= 0; i < T; ++i){
		// 	for(int j = 0; j < Vp[i].size(); ++j){
		// 		printf("%d ", Vp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		for(int i= 0; i < T; ++i){
			if(dfn[i] == -1){
				Tarjan(i, i);
			}
		}
		sort(Vans.begin(), Vans.end(), cmp);
		printf("%d critical links\n", Vans.size());
		while(!Vans.empty()){
			printf("%d - %d\n", Vans[0].l, Vans[0].r);
			Vans.erase(Vans.begin());
		}
		printf("\n");

	}
	return 0;
}
