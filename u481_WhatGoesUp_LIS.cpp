#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	vector<int> V;
	int t;
	while(scanf("%d", &t) != EOF)
		V.push_back(t);
	int N = V.size();
	int pre[N];
	vector<int> VLIS; // can create a struct for VLIS and Vindex
	vector<int> Vindex;
	for (int i = 0; i < N; ++i){ // 感觉相同长度时要取先出现的好像就不能用这方法了……？
		int j = lower_bound(VLIS.begin(), VLIS.end(), V[i]) - VLIS.begin();
		if(j == VLIS.size()){
			VLIS.push_back(V[i]);
			Vindex.push_back(i);
		}else{
			VLIS[j] = V[i];
			Vindex[j] = i;
		}
		pre[i] = j > 0 ? Vindex[j-1] : j; // when j == 0 then pre is useless
	}
	int length = VLIS.size();
	printf("%d\n-\n", length);
	stack<int> S;
	int last = Vindex[length-1];
	while(length--){
		S.push(V[last]);
		last = pre[last];
	}
	while(!S.empty()){
		int tmp = S.top();
		printf("%d\n", tmp);
		S.pop();
	}
	return 0;
}