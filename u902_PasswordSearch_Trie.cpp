#include <cstdio>
#include <cstring>
#define MAXN 10000
struct Trie{
	int count;
	int child[26];
}T[100005];
char str[MAXN];
int Max;
int num;
char ans[12];

void makeTrie(int n, char* b){
	int i = 0;
	char tmp[12];
	strncpy(tmp, b, n);
	tmp[n] = '\0';
	while(n--){
		const int b_int = *b - 'a';
		if(T[i].child[b_int] == 0)
			T[i].child[b_int] = ++num;
		i = T[i].child[b_int];
		++b;
	}
	++T[i].count;
	if(T[i].count > Max){
		Max = T[i].count;
		strcpy(ans, tmp);
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		Max = 0;
		num = 0;
		memset(T, 0, sizeof T);
		scanf("%s", str);
		const int len = strlen(str);
		for (int i = 0; i < len - n + 1; ++i){
			makeTrie(n, str + i);
		}
		printf("%s\n", ans);
	}
}