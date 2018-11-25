#include <cstdio>
#include <cstring>
#include <queue>

#define MAXN 201
#define NEIGHB 6

using namespace std;

struct Pos{
	int x, y;
};

char map[MAXN][MAXN];
int n;
bool inqueue[MAXN][MAXN];

queue< Pos > Q;

Pos neighbors_dis[NEIGHB] = {
	{.x = -1, .y = -1},
	{.x = -1, .y = 0},
	{.x = 0, .y = -1},
	{.x = 0, .y = 1},
	{.x = 1, .y = 0},
	{.x = 1, .y = 1}
};

inline bool is_black(char c){
	return c == 'b';
}

bool BFS_black(){
	memset(inqueue, false, sizeof(inqueue));
	for(int i = 0; i < n; ++i){
		if(is_black(map[0][i])){
			Pos pos = {.x = 0, .y = i};
			inqueue[0][i] = true;
			Q.push(pos);
		}
	}
	while(!Q.empty()){
		Pos pos = Q.front();
		Q.pop();
		for (int i = 0; i < NEIGHB; ++i){
			int x = pos.x + neighbors_dis[i].x;
			int y = pos.y + neighbors_dis[i].y;
			if(x >= 0 && x < n && y >= 0 && y < n && is_black(map[x][y]) && !inqueue[x][y]){
				if (x == n-1){
					while(!Q.empty())
						Q.pop();
					return true;
				}
				inqueue[x][y] = true;
				Pos pos_ = {.x = x, .y = y};
				Q.push(pos_);
			}
		}
	}
	return false;
}

int main(){
	int T = 0;
	while(scanf("%d\n", &n)==1 && n){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				map[i][j] = getchar();
			while(getchar()!='\n');
		}
		bool black_win = BFS_black();
		printf("%d %c\n", ++T, black_win ? 'B' : 'W');
	}
	return 0;
}
