#include <cstdio>
#include <cstring>
// WA QQ
struct Trie{
	bool used;
	bool end;
	int child[10];
}Tr[100005];
bool cannot;
int num;
void makeTrie(char* b){
	int i = 0;
	int notUsed = 0;
	bool existed;
	while(*b){
		// printf("a\n");
		const int b_int = *b - '0';
		if(Tr[i].child[b_int] == 0){
			Tr[i].child[b_int] = ++num;
		}
		i = Tr[i].child[b_int];
		if(!Tr[i].used){
			Tr[i].used = true;
			++notUsed;
		}
		if(Tr[i].end){
			existed = true;
		}
		++b;
	}
	Tr[i].end = true;
	if(notUsed == 0 || existed)
		cannot = true;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(Tr, 0, sizeof Tr);
		int N;
		scanf("%d", &N);
		cannot = false;
		num = 0;
		while(N--){
			char str[12];
			scanf("%s", str);
			makeTrie(str);
		}
		if(cannot)
			printf("No\n");
		else
			printf("Yes\n");
	}
}