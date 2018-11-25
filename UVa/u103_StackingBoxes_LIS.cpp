#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
struct box{
	int index;
	int dimen[11];
};

bool cmp(box a, box b){
	for (int i = 0; i < 11; ++i)
		if(a.dimen[i] != b.dimen[i])
			return a.dimen[i] < b.dimen[i];
	return true;
}

bool smaller(box a, box b, int n){
	for (int i = 0; i < n; ++i)
		if(a.dimen[i] >= b.dimen[i])
			return false;
	return true;
}

int main(){
	int k, n;
	while(scanf("%d%d", &k, &n) != EOF){
		box B[35];
		for (int i = 1; i <= k; ++i)
		{
			B[i].index = i;
			for (int j = 0; j < n; ++j)
				scanf("%d", &B[i].dimen[j]);
			sort(B[i].dimen, B[i].dimen + n);
		}
		sort(B + 1, B + 1 + k, cmp);
		// for (int i = 1; i <= k; ++i)
		// {
		// 	printf("%d ", B[i].index);
		// 	for (int j = 0; j < n; ++j)
		// 		printf("%d ", B[i].dimen[j]);
		// 	puts("");
		// }
		int LIS[k+1];
		int pre[k+1];
		int Max = 1;
		int last = -1;
		for (int i = 1; i <= k; ++i)
		{
			LIS[i] = 1;
			for (int j = 1; j < i; ++j){
				if(smaller(B[j], B[i], n) && LIS[j] >= LIS[i]){ //CHECK : if same length which one to save
					LIS[i] = LIS[j] + 1;
					pre[i] = j;
					if((LIS[i] > Max) || (LIS[i] == Max && j < B[pre[i]].index)){

						Max = LIS[i];
						last = i;
					}
				}
			}
		}
		printf("%d\n", Max);
		stack<box> S;
		while(Max--){
			S.push(B[last]);
			last = pre[last];
		}
		while(!S.empty()){
			if(++Max) // !fisrt
				putchar(' ');
			box t = S.top();
			printf("%d", t.index);
			S.pop();
		}
		puts("");
	}
}