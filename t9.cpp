#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

struct P
{
	unsigned int n;
	int value;
}p[MAXN];

bool cmp(P a, P b){
	return a.n < b.n;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(p, 0, sizeof p);
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> p[2*i].n;
			p[2*i].value = 1;
			cin >> p[2*i + 1].n;
			p[2*i + 1].value = -1;
		}
		sort(p, p+2*m, cmp);
		int Max = 0;
		int tmp = 0;
		for (int i = 0; i < 2*m; ++i){
			// cout << p[i].n << " " << p[i].value << endl;
			tmp += p[i].value;
			Max = max(Max, tmp);
		}

		cout << Max << endl;
	}
	return 0;
}