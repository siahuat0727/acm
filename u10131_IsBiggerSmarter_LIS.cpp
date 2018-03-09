#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct elephant{
	int index;
	int weight;
	int IQ;
};

bool cmp(elephant a, elephant b){
	return a.weight > b.weight;
}

bool cmp2(elephant a, int b){
	return a.IQ <= b;
}
int main(){
	elephant E[1005];
	elephant t;
	int n = 1;
	while(scanf("%d %d", &E[n].weight, &E[n].IQ) != EOF){
		E[n].index = n;
		++n;
	}

	sort(E+1, E+n, cmp);
	int LIS[n];
	int pre[n];
	int Max = 1;
	int last;
	vector<elephant> VLIS; // can create a struct for VLIS and Vindex
	vector<int> Vindex;
	// for (int i = 1; i < n; ++i){
	// 	printf("qq %d %d %d\n", E[i].weight, E[i].IQ, E[i].index);
	// }
	for (int i = 1; i < n; ++i){
		LIS[i] = 1;
		for (int j = 1; j < i; ++j){
			if(E[j].IQ < E[i].IQ && E[j].weight > E[i].weight && LIS[j] >= LIS[i]){ //CHECK : if same length which one to save (some case may use LIS[j]+1>=LIS[i])
				LIS[i] = LIS[j] + 1;
				pre[i] = j;
				if(LIS[i] > Max){ // CHECK2 : if same length
					Max = LIS[i];
					last = i;
				}
			}
		}
	}
	printf("%d\n", Max);
	// stack<elephant> S;
	while(Max--){
		// S.push(E[last]);
		printf("%d\n",E[last].index);
		last = pre[last];
	}
	return 0;

/*
	int length = VLIS.size();
	queue<elephant> Q;
	int last = Vindex[length-1];
	// printf("qq\nq\n");
	for (int i = 0; i < length; ++i){
		// printf("qq %d %d %d \n", E[last].weight, E[last].IQ, E[last].index);
		Q.push(E[last]);
		last = pre[last];
	}
	queue<elephant> Qans;
	int last_weight = -1;
	while(!Q.empty()){
		elephant tmp = Q.front();
		Q.pop();
		if(tmp.weight != last_weight)
			Qans.push(tmp);
		last_weight = tmp.weight;
	}
	printf("%d\n", Qans.size());
	while(!Qans.empty()){
		elephant tmp = Qans.front();
		printf("%d %d %d\n", tmp.index, tmp.weight, tmp.IQ);
		Qans.pop();
	}
*/
}