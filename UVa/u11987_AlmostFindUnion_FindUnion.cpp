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

#define MAXN 100005
#define PB push_back

int p[MAXN];
vector<int> V[MAXN];

int Find(int x){
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);

	if(x != y){
		int sz = V[x].size();
		for (int i = 0; i < sz; ++i)
		{
			// printf("qq %d %d\n", i, V[x][i]);
			V[y].PB(V[x][i]);
			p[V[x][i]] = y;
		}
		V[x].clear();

	}
}

void move(int x, int y){
	int X = Find(x);
	int Y = Find(y);

	if(X == Y)
		return;
	V[X].erase(find(V[X].begin(), V[X].end(), x));
	V[Y].PB(x);
	p[x] = Y;

}

void printAns(int x){
	x = Find(x);
	int sz = V[x].size();
	int sum = 0;
	for (int i = 0; i < sz; ++i){
		sum += V[x][i];
	}
	printf("%d %d\n", sz, sum);
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for (int i = 0; i <= n; ++i){
			p[i] = i;
			V[i].clear();
			V[i].PB(i);
		}
		while(m--){
			int op, x, y;
			scanf("%d", &op);

			switch(op){
				case 1:	scanf("%d%d", &x, &y);
						Union(x, y);
						break;
				case 2:	scanf("%d%d", &x, &y);
						move(x, y);
						break;
				case 3:	scanf("%d", &x);
						printAns(x);
						break;
			}
		}
	}
    return 0;
}