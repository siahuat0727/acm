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
#define MAXN 2005
int p[MAXN];

struct Edge
{
	int l, r, d;
}E;

vector<Edge> V;

bool cmp(Edge a, Edge b){
	return a.d < b.d;
}

bool cmp2(Edge a, Edge b){
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}

int Find(int x){
	return x == p[x] ? x : p[x] = Find(p[x]);
}

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
	return x == y ? false : true;
}

int main() {
    int s, c;
    scanf("%d%d", &s, &c);
	V.clear();
    vector<Edge> Vans;
	for (int i = 1; i <= s; ++i){
		p[i] = i;
	}
	for (int i = 0; i < c; ++i){
        int l, r, d;
		cin >> l >> r >> d;
        if(l != r){
            Edge e = {l, r, d};
            V.push_back(e);
        }
	}
	int choose = 0;
	sort(V.begin(), V.end(), cmp);
    int Max = 0;
	for(int i = 0; i < V.size() && choose != s-1; ++i){
		if(Union(V[i].l, V[i].r)){
			Max = max(Max, V[i].d);
            // Vans.push_back(V[i]);
			choose++;
		}
	}
	printf("%d\n", Max);
    // sort(Vans.begin(), Vans.end(), cmp2);
    // printf("%d\n%d\n", Max, Vans.size());
    // while(!Vans.empty()){
    //     printf("%d %d\n", Vans[0].l, Vans[0].r);
    //     Vans.erase(Vans.begin());
    // }
    return 0;
}
