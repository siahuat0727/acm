#include <cstdio>
#include <cstring>

#define MAXN 15

struct Piece{
	int x, y;
}pieces[MAXN];

int n, m;
int i1, i2, d1, d2;
bool vis[MAXN];

bool BT(int depth, int prevLen){
	if(depth == n)
		return prevLen == d1;
	for(int i = 0; i < m; ++i){
		if(!vis[i] && (pieces[i].x == prevLen || pieces[i].y == prevLen)){
			vis[i] = true;
			if(BT(depth+1, pieces[i].x + pieces[i].y - prevLen))
				return true;
			vis[i] = false;
		}
	}
	return false;
}

int main(){
	while(scanf("%d", &n) && n){
		scanf("%d%d%d%d%d", &m, &i1, &i2, &d1, &d2);
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &pieces[i].x, &pieces[i].y);
		memset(vis, false, sizeof(vis));
		puts(BT(0, i2) ? "YES" : "NO");
	}	
}
