#include <cstdio>

#define N 6

int k;
int S[15];
int solution[N];

void backTracking(int dimension){
	if(dimension == N){
		for (int i = 0; i < N; ++i){
			if(i)
				printf(" ");
			printf("%d", S[solution[i]]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < k; ++i){
		if(dimension > 0 && i <= solution[dimension - 1])
			continue;
		solution[dimension] = i;
		backTracking(dimension + 1);
	}
}

int main(){
	bool first = true;
	while(scanf("%d", &k) && k != 0){
		if(first)
			first = false;
		else
			printf("\n");
		for (int i = 0; i < k; ++i)
			scanf("%d", &S[i]);
		backTracking(0);
	}
	return 0;
}