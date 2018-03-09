#include <cstdio>
#include <stack>
using namespace std;

#define MAXN 100
bool r[MAXN+1];
bool c[MAXN+1];
bool d1[2*MAXN-1];
bool d2[2*MAXN-1];
char ques[MAXN+1][MAXN+1];
char ans[MAXN+1][MAXN+1];
char tmp[MAXN+1][MAXN+1];
int n, m;

struct CIJ{
	char c;
	int i;
	int j;
};

void func(int i, int j){
	// printf("%d %d\n", i, j);

	// 	for (int x = 1; x <= n; ++x){
	// 		for (int y = 1; y <= n; ++y){
	// 			printf("%c ", tmp[x][y]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");

	if(i > n){
		// printf("good\n");
		// for (int x = 1; x <= n; ++x){
		// 	for (int y = 1; y <= n; ++y){
		// 		printf("%c ", tmp[x][y]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		return ;

	}
	int next_i = i, next_j = j+1;
	if(next_j > n){
		++next_i;
		next_j = 1;
	}
	if(tmp[i][j] == '.'){
		if(!r[i] && !c[j]){
			r[i] = c[j] = true;
			tmp[i][j] = 'x';
			func(next_i, next_j);
			// r[i] = c[j] = false;
			return;
		}
		if(!d1[i-j+n-1] && !d2[i+j-2]){
			d1[i-j+n-1] = d2[i+j-2] = true;
			tmp[i][j] = '+';
			func(next_i, next_j);
			// d1[i-j+n-1] = d2[i+j-2] = false;
			return;
		}
		tmp[i][j] = '.';
	}	
	func(next_i, next_j);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case){
		scanf("%d %d%*c", &n, &m);
		for (int i = 1; i <= n; ++i)
			r[i] = c[i] = false;
		for (int i = 0; i < 2*n-1; ++i)
			d1[i] = d2[i] = false;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				tmp[i][j] = ques[i][j] = '.';
		while(m--){
			char ch;
			int i, j;
			scanf("%c %d %d%*c", &ch, &i, &j);
			if(ch != 'x')
				d1[i-j+n-1] = d2[i+j-2] = true;
			if(ch != '+')
				r[i] = c[j] = true;
			tmp[i][j] = ques[i][j] = ch;
		}

		func(1, 1);
		int num = 0;
		int diff = 0;
		stack<CIJ> S;

		// printf("\n");
		// for (int x = 1; x <= n; ++x){
		// 	for (int y = 1; y <= n; ++y){
		// 		printf("%c ", tmp[x][y]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				char ch = tmp[i][j];
				if(ch == '+'){
					++num;
					if(!r[i] && !c[j]){
						tmp[i][j] = ch = 'o';
						r[i] = c[j] = true;
						++num;
					}
				}
				else if(ch == 'x'){
					++num;
					if(!d1[i-j+n-1] && !d2[i+j-2]){
						tmp[i][j] = ch = 'o';
						d1[i-j+n-1] = d2[i+j-2] = true;
						++num;
					}
				}
				else if(ch == 'o'){
					num += 2;
				}
				if(ch != ques[i][j]){
					CIJ cij = {ch, i, j};
					S.push(cij);
				}
			}
		}

		// printf("\n");
		// for (int x = 1; x <= n; ++x){
		// 	for (int y = 1; y <= n; ++y){
		// 		printf("%c ", tmp[x][y]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		printf("Case #%d: %d %d\n", Case, num, S.size());
		while(!S.empty()){
			CIJ cij = S.top();
			S.pop();
			printf("%c %d %d\n", cij.c, cij.i, cij.j);
		}
	}
	return 0;
}
