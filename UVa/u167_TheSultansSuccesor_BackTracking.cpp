#include <cstdio>
#define N 8;

int k;
int chess[N][N];
int solution[N][2];
bool col[N];
bool left[15], right[15];

void backTrancking(int dimension){
	if(dimension == N){

		return;
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if(!col[j] && !left[j-1] && !right[(15+j-i)%15])
		}
	}
}

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &chess[i][j]);
		backTrancking(0);
	}
}