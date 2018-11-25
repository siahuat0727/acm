#include <cstdio>
#include <cstring>

struct Trie{
	char ans[11];
	int child[26];
}T[1000005];

int num = 0;
void makeTrie(const char* a, char* b){
	int i = 0;
	while(*b){
		// printf("a\n");
		const int b_int = *b - 'a';
		if(T[i].child[b_int] == 0)
			T[i].child[b_int] = ++num;
		i = T[i].child[b_int];
		++b;
	}
	strcpy(T[i].ans, a);
}

int main(){
	char str[25];
	while(gets(str) && *str){
		char a[11], b[11];
		sscanf(str, "%s %s", a, b);
		makeTrie(a, b);
	}
	while(gets(str)){
		const int len = strlen(str);
		int now = 0;
		bool found = true;
		for (int i = 0; i < len; ++i){
			const int c = str[i] - 'a';
			if(T[now].child[c] == 0){
				found = false;
				break;
			}
			now = T[now].child[c];
		}
		if(found)
			printf("%s\n", T[now].ans);
		else
			printf("eh\n");
	}
	return 0;
}