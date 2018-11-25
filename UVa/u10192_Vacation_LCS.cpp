#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
int main(){
	char a[N];
	char b[N];
	int LCS[N][N];
	int T = 0;
	while(gets(a) && a[0] != '#'){
		++T;
		gets(b);
		int aLength = strlen(a);
		int bLength = strlen(b);
		for (int i = 0; i <= aLength; ++i)
			LCS[i][0] = 0;
		for (int i = 1; i <= bLength; ++i)
			LCS[0][i] = 0;
		for (int i = 1; i <= aLength; ++i){
			for (int j = 1; j <= bLength; ++j){
				if(a[i-1] == b[j-1]){// if the zero index is used, then cmp i-1 j-1
					LCS[i][j] = LCS[i-1][j-1] + 1;
				}else{
					if(LCS[i-1][j] >= LCS[i][j-1]){
						LCS[i][j] = LCS[i-1][j];
					}else{
						LCS[i][j] = LCS[i][j-1];
					}
				}
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", T, LCS[aLength][bLength]);
	}
}