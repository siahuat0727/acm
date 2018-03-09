#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct cow{
	int first;
	int second;
	int order;
};

bool cmp1(cow a, cow b){
	return a.first > b.first ;
}

bool cmp2(cow a, cow b){
	return a.second > b.second ;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<cow> V;
	for (int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		cow tmp = {a, b, i+1};
		V.push_back(tmp);
	}
	sort(V.begin(), V.end(), cmp1);
	sort(V.begin(), V.begin()+k, cmp2);
	printf("%d\n", V[0].order);	
}