#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int A, B, N;
bool happened[1001][1001];
vector<string> V;

void DFS(int a, int b){
	if(a == N || b == N)
		return;
	if(happened[a][b])
		return;
	happened[a][b] = true;
	if
}

int main(){
	while(scanf("%d %d %d", &A, &B, &N) != EOF){
		V.clear();
		for (int i = 0; i <= B; ++i)
			for (int j = 0; j <= B; ++j)
				happened[i][j] = false;
		DFS(0, 0);
		while(!V.empty()){
			printf("%s\n", V[0]);
			V.erase(V.begin());
		}
		printf("success\n");
	}
	return 0;
}