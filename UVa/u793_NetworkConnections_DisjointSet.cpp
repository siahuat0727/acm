#include <cstdio>
#include <cstdlib>
#include <cstring>
#define BUF_N 100
int *p = NULL;

inline int Find(int x){
	return x == p[x] ? x : p[x] = Find(p[x]);
}

inline void Union(int x, int y){
	p[Find(x)] = Find(y);
}

inline bool check_connection(int x, int y){
	return Find(x) == Find(y);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d\n", &n);

		p = (int*)realloc(p, (n+1)*sizeof(int));
		for (int i = 1; i <= n; ++i)
			p[i] = i;

		char c;
		int x, y;
		int succ, fail;
		succ = fail = 0;
		char str[BUF_N+1];
		while(fgets(str, BUF_N, stdin) != NULL && strlen(str) > 2){
			sscanf(str, "%c %d %d\n", &c, &x, &y);
			if(c == 'c'){
				Union(x, y);
			}else if (c == 'q'){
				if(check_connection(x, y))
					succ++;
				else
					fail++;
			}else{
				perror("unexpected op");
			}
		}

		printf("%d,%d\n", succ, fail);
		if(T)
			putchar('\n');
	}
	free(p);

}
