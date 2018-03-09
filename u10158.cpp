#include <cstdio>

int p[10005];
int e[10005];
#define NO_ENEMIES(n) ((e[n]) == -1)

int Find(int x){
	if(x == p[x])
		return x;
	return p[x] = Find(p[x]);
}


void areEnemies(int x, int y){
	printf("%d\n", e[Find(x)] == Find(y));
}

void areFriends(int x, int y){
	printf("%d\n", Find(x) == Find(y));
}

void setEnemies(int x, int y){
	x = Find(x);
	y = Find(y);

	if(x == y){
		printf("-1\n");
		return;
	}

	if(NO_ENEMIES(x) && NO_ENEMIES(y)){
		e[x] = y;
		e[y] = x;
	}else if(NO_ENEMIES(x))
		p[x] = e[y];
	else if(NO_ENEMIES(y))
		p[y] = e[x];
	else{
		p[y] = e[x];
		p[e[y]] = x;
	}	
}

void setFriends(int x, int y){
	x = Find(x);
	y = Find(y);

	if(NO_ENEMIES(x) && NO_ENEMIES(y))
		p[x] = y;
	else if(NO_ENEMIES(x))
		p[x] = y;
	else if(NO_ENEMIES(y))
		p[y] = x;
	else if(e[x] == y)
		printf("-1\n");
	else{
		p[x] = y;
		p[e[x]] = e[y];
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		p[i] = i;
		e[i] = -1;
	}
	int op, x, y;
	while(scanf("%d %d %d", &op, &x, &y) && !(op == 0 && x == 0 && y == 0)){
		switch(op){
			case 1:	setFriends(x, y);
					break;
			case 2:	setEnemies(x, y);
					break;
			case 3:	areFriends(x, y);
					break;
			case 4:	areEnemies(x, y);
					break;
		}
	}
	return 0;
}

