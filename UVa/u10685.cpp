#include <cstdio>
#include <map>
#include <string>
using namespace std;


int p[5000];
int n[5000];

int Find(int x){
	if(x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main(){
	int c, r;
	while(scanf("%d %d%*c", &c, &r) && !(c == 0 && r == 0)){
		map<string, int> M;
		for (int i = 0; i < c; ++i){
			p[i] = i;
			n[i] = 0;
			char name[35];
			scanf("%s", name);
			M[name] = i;
		}
		while(r--){
			char low[35];
			char high[35];
			scanf("%s %s", low, high);
			Union(M[low], M[high]);
		}
		for (int i = 0; i < c; ++i)
			++n[Find(i)];
		int Max = 0;
		for (int i = 0; i < c; ++i)
			Max = n[i] > Max ? n[i] : Max;
		printf("%d\n", Max);
	}
	return 0;
}