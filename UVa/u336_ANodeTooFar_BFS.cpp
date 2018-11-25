#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

#define MAXN 10000
#define PB push_back

using namespace std;

struct S{
	int node, ttl;
};

int n;
bool inqueue[MAXN];

queue<S> Q;
map<int, int> M;
vector<int> V[MAXN];

void BFS(int src, int ttl){
	if(ttl < 0)
		return;
	S s = {.node = src, .ttl = ttl};
	Q.push(s);
	inqueue[src] = true;
	while(!Q.empty()){
		S s = Q.front();
		Q.pop();
		if (s.ttl <= 0)
			continue;
		for (int node : V[s.node]){
			if (!inqueue[node]){
				inqueue[node] = true;
				S s_ = {.node = node, .ttl = s.ttl-1};
				Q.push(s_);
			}
		}
	}
}

inline void map_try_insert(int n, int& index){
	if(M[n] == 0)
		M[n] = index++;
}

int main(){
	int T = 0;
	while(scanf("%d\n", &n)==1 && n){
		for(int i = 1; i <= 2*n; ++i)
			V[i].clear();
		M.clear();

		int index = 1;
		for(int i = 0; i < n; ++i){
			int x, y;
			scanf("%d %d", &x, &y);
			map_try_insert(x, index);
			map_try_insert(y, index);
			int x_ = M[x];
			int y_ = M[y];
			V[x_].PB(y_);
			V[y_].PB(x_);
		}
		int src, ttl;
		while(scanf("%d %d", &src, &ttl)==2 && (src || ttl)){
			memset(inqueue, false, sizeof(inqueue));
			BFS(M[src], ttl);
			int ans = 0;
			for (int i = 1; i < index; ++i)
				if(inqueue[i] == false)
					++ans;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++T, ans, src, ttl);
		}
	}
	return 0;
}
