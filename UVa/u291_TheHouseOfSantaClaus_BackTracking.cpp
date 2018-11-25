#include <cstdio>
#include <algorithm>
using namespace std;
#define N 9
bool path[6][6] = {	{0, 0, 0, 0, 0, 0},
					{0, 0, 1, 1, 0, 1},
					{0, 0, 0, 1, 0, 1},
					{0, 0, 0, 0, 1, 1},
					{0, 0, 0, 0, 0, 1},
					{0, 0, 0, 0, 0, 0}};

int solution[N] = {1};

void backTracking(int dimension){
	if(dimension == N){
		for (int i = 0; i < N; ++i)
			printf("%d", solution[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= 5; ++i){
		// printf("dimension = %d i = %d\n", dimension, i);
		int Max = max(solution[dimension-1], i);
		int Min = min(solution[dimension-1], i);
		if(path[Min][Max]){
			solution[dimension] = i;
			path[Min][Max] = false;
			backTracking(dimension + 1);
			path[Min][Max] = true;
		}
	}
}

int main(){
	backTracking(1);
	return 0;
}