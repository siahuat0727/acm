#include <cstdio>
#include <queue>
using namespace std;

int x, y, z;
#define NOT_A_CELL(p) (step_able[p.tx][p.ty][p.tz])
#define NEVER_BEEN_STEP(p) (!stepped[p.tx][p.ty][p.tz])
#define INSIDE_THE_DUNGEONS(p) (p.tx >=0 && p.tx < x && p.ty >= 0 && p.ty < y && p.tz >= 0 && p.tz < z)
bool stepped[32][32][32];
bool step_able[32][32][32];
int direction[3][6] = {{0,0,0,0,1,-1},{0,0,1,-1,0,0},{1,-1,0,0,0,0}};

struct point{
	int tx, ty, tz;
	int time;
	bool operator==(const point &rhs)const{
		return tx==rhs.tx && ty==rhs.ty && tz==rhs.tz;
	}
};

int BFS(point start, point end){
	queue<point> Q;
	Q.push(start);
	while(!Q.empty()){
		point now = Q.front();
		Q.pop();
		stepped[now.tx][now.ty][now.tz] = true;
		// printf("%d %d %d\n", now.tx, now.ty, now.tz);
		for (int i = 0; i < 6; ++i){
			point tmp = {now.tx + direction[0][i], now.ty + direction[1][i], now.tz + direction[2][i], now.time + 1};
			if(!INSIDE_THE_DUNGEONS(tmp))
				continue;
			if(tmp == end)
				return tmp.time;
			else if(NOT_A_CELL(tmp) && NEVER_BEEN_STEP(tmp)){
				Q.push(tmp);
			}

		}
	}
	return -1;
}

int main(){
	while(scanf("%d %d %d", &x, &y, &z) && !(x == 0 && y == 0 && z == 0)){
		getchar();
		point start, end;
		for (int i = 0; i < x; ++i){
			for (int j = 0; j < y; ++j){
				for (int k = 0;k < z; ++k){
					char c;
					scanf("%c", &c);
					switch(c){
						case	'S':	start.tx = i;
										start.ty = j;
										start.tz = k;
										stepped[i][j][k] = true;
										step_able[i][j][k] = false;
										start.time = 0;
										break;
						case	'E':	end.tx = i;
										end.ty = j;
										end.tz = k;
										stepped[i][j][k] = false;
										step_able[i][j][k] = true;
										break;
						case	'.':	stepped[i][j][k] = false;
										step_able[i][j][k] = true;
										break;
						case	'#':	stepped[i][j][k] = false;
										step_able[i][j][k] = false;
										break;
					}
				}
				getchar();
			}
			getchar();
		}
		const int total = BFS(start, end);
		if(total != -1)
			printf("Escaped in %d minute(s).\n", total);
		else
			printf("Trapped!\n");
	}
	return 0;
}