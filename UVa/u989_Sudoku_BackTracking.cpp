#include <cstdio>
int S[9][9];
int n;
int size;

void backTracking(int x, int y){
	if(S[x][y] != 0){
		bac
	}
	for (int i = 1; i <= size; ++i) {
		
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		size = n*n;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				scanf("%d", &S[i][j]);
		backTracking();		
	}
}