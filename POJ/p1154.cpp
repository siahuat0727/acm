#include <cstdio>
using namespace std;
char c[20][20];
int n, m;
bool exist[30];
int Max;

void DFS(int x, int y, int step){
	if(x < 0 || x >= n || y < 0 || y >= m)
		return;
	const int index = c[x][y] - 'A';
	if(exist[index])
		return;
	exist[index] = true;	
	step++;
	Max = step > Max ? step : Max;
	DFS(x, y+1, step);
	DFS(x+1, y, step);
	DFS(x, y-1, step);
	DFS(x-1, y, step);
	step--;
	exist[index] = false;
}

int main(){
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			scanf("%c", &c[i][j]);
		getchar();
	}
	DFS(0, 0, 0);
	printf("%d\n", Max);
	return 0;
}