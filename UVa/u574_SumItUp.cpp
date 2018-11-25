#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, n;
int arr[15];
vector<int> all[10000];
vector<int> solution(15);


void backTracking(int dimension, int sum, int index, int &line){
	for (int i = index; i < n; ++i){
		solution[dimension] = arr[i];
		int tmp = sum + arr[i];
		if(tmp > t)
			continue;
		else if(tmp == t){
			all[line++] = solution;
		}else{
			backTracking(dimension + 1, tmp, i + 1, line);
		}
	}
	solution[dimension] = 0;
}

bool decreasing(vector<int> x,vector<int> y){
	int minSize = min(x.size(), y.size());
	for (int i = 0; i < minSize; ++i){
		if(x[i] != y[i])
			return x[i] > y[i];
	}
	return x.size() > y.size();

}

int main(){
	while(scanf("%d %d", &t, &n) && n != 0){
		printf("Sums of %d:\n", t);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		int line = 0;
		backTracking(0, 0, 0, line);
		if(line == 0)
			printf("NONE\n");
		else{
			sort(all, all+line, decreasing);
			for (int i = 0; i < line; ++i){
				if(i > 0 && all[i] == all[i-1])
					continue;
				printf("%d", all[i][0]);
				for (int j = 1; all[i][j] != 0; ++j)
					printf("+%d", all[i][j]);
				printf("\n");
				
			}
		}
	}
	return 0;
}