#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 105
#define INF 1000000

int pa[MAXN];
bool v[MAXN];

using namespace std;

int cap[MAXN][MAXN];
int flow[MAXN][MAXN];

bool DFS(int cur, int t, int n){
	v[cur] = true;
	if(cur == t)
		return true;
	for(int i = 1; i <= n; ++i){
		if(v[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			pa[i] = cur;
			if(DFS(i, t, n))
				return true;
		}
	}
	return false;
}

int FindFlow(int s, int t, int n){
	int pre;
	int f = INF;
	for(int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i]>0)
			f = min(f, cap[pre][i] - flow[pre][i]);
		else
			f = min(f, flow[i][pre]);
	}
	for (int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i] > 0)
			flow[pre][i] += f;
		else
			flow[i][pre] -= f;
	}
	return f;
}

int FordFulkerson(int s, int t, int n){
	int ret = 0;
	while(1){
		// printf("ret = %d\n", ret);
		memset(v, 0, sizeof(v));
		if(!DFS(s, t, n)) // source, end, totalV
			break;
		ret += FindFlow(s, t, n);
	}
	return ret;
}

int getIndex(char c){
	switch(c){
		case 'S': return 1;
		case 'M': return 2;
		case 'L': return 3;
		case 'X': return 4;
		case 'T': return 5;
	}
	return -1;
}

int main() {
	string str;
	while((cin >> str) && str == "START"){
		memset(cap, 0, sizeof cap);
		memset(flow, 0, sizeof flow);
		int n;
		cin >> n;
		const int s = 5 + n + 1;
		const int t = 5 + n + 2;
		for (int i = 1; i <= n; ++i){
			cin >> str;
			int start = getIndex((char)str[0]);
			int end = getIndex((char)str[1]);
			for(int j = start; j <= end; ++j){
				cap[5+i][j] = 1;
			}
			cap[s][5+i] = 1;
		}
		for (int i = 1; i <= 5; ++i){
			int tmp;
			cin >> tmp;
			cap[i][t] = tmp;
		}
		cin >> str;
		int ans = FordFulkerson(s, t, t);
		if(ans == n)
			printf("T-shirts rock!\n");
		else
			printf("I'd rather not wear a shirt anyway...\n");
	}
}