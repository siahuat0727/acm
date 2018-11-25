#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;
// WA=.=
int main(){
	int T;
	scanf("%d%*c", &T);
	getchar();
	while(T--){
		char str[100];
		vector<int> V;
		while(gets(str)!=NULL && str[0]!='\0'){
			V.push_back(atoi(str));
		}
		const int length = V.size();
		int LIS[length];
		int pre[length];
		int Max = 1;
		int last = -1;
		for (int i = 0; i < length; ++i){// [first,last]
			LIS[i] = 1;
			for (int j = 0; j < i; ++j){
				if(V[j] < V[i] && LIS[j] >= LIS[i]){ //CHECK : if same length which one to save (some case may use LIS[j]+1>=LIS[i])
					LIS[i] = LIS[j] + 1;
					pre[i] = j;
					if(LIS[i] > Max){ // CHECK2 : if same length
						Max = LIS[i];
						last = i;
					}
				}
			}
		}
		printf("Max hits: %d\n", Max);
		stack<int> S;
		while(Max--){
			S.push(V[last]);
			last = pre[last];
		}
		while(!S.empty()){
			int t = S.top();
			printf("%d\n", t);
			S.pop();
		}
		if(T){
			puts("");
		}
	}
}