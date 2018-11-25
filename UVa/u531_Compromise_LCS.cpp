#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define UP (1)
#define RI (-1)
int main(){
	int n, m;
	char a[102][31], b[102][31];
	while(scanf("%s", a[1]) != EOF){
		n = 2;
		m = 1;
		int pre[102][102] = {0};
		int LCS[102][102] = {0};
		while(scanf("%s", a[n]) && a[n][0] != '#')
			++n;
		while(scanf("%s", b[m]) && b[m][0] != '#')
			++m;
		for (int i = 1; i < n; ++i){
			for (int j = 1; j < m; ++j){
				if(strcmp(a[i], b[j]) == 0){
					pre[i][j] = 0;
					LCS[i][j] = LCS[i-1][j-1] + 1;
				}else{
					int up = LCS[i-1][j];
					int ri = LCS[i][j-1];
					if(up >= ri){
						pre[i][j] = UP;
						LCS[i][j] = up;
					}else{
						pre[i][j] = RI;
						LCS[i][j] = ri;
					}
				}
			}
		}
		stack<char*>S;
		--n;
		--m;
		while(n > 0 && m > 0){
			switch(pre[n][m]){
				case  0:	S.push(a[n]);
							--n;
							--m;
							break;
				case UP:	--n;
							break;
				case RI:	--m;
							break;
			}
		}
		int i = 0;
		while(!S.empty()){
			if(i++)
				printf(" ");
			printf("%s", S.top());
			S.pop();
		}
		puts("");
	}
}