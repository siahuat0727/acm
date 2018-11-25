#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[25];
vector<int> vtmp;
vector<int> solution;
int N;
int t;
bool finish;
int Max;

void backTracking(int dimension, int sum, int index){
	for (int i = index; i < t; ++i){
		int tmp = sum + arr[i];
		if(finish)
			return;
		if(tmp > N)
			continue;
		vtmp.push_back(arr[i]);
		if(tmp == N){
			solution = vtmp;
			finish = true;
		}else{
			if(tmp > Max){
				solution = vtmp;
				Max = tmp;
			}
			backTracking(dimension + 1, tmp, i + 1);
		}
		vtmp.pop_back();
	}
}

int main(){
	while(scanf("%d", &N) != EOF){
		scanf("%d", &t);
		for (int i = 0; i < t; ++i)
			scanf("%d", &arr[i]);
		finish = false;
		Max = 0;
		vtmp.clear();
		backTracking(0, 0, 0);
		int sum = 0;
		for (int i = 0; i < solution.size(); ++i){
			printf("%d ", solution[i]);
			sum += solution[i];
		}
		printf("sum:%d\n", sum);
	}
	return 0;
}