#include <cstdio>
#include <cstring>

#define MAXN 1000000
#define prime_mod 1073676287
typedef long long T;
char str1[10000+5];
char str2[MAXN+5];
T h[MAXN+5]; //hash 阵列
T h_base[MAXN+5]; //h_base[n] = (prime^n)%prime_mod

inline void hash_init(char* str, int len, T prime = 0xdefaced){
	h_base[0] = 1;
	for (int i = 1; i <= len; ++i){
		h[i] = (h[i-1]*prime + str[i-1]) % prime_mod;
		h_base[i] = (h_base[i-1]*prime) % prime_mod;
	}
}

inline T get_hash(int l, int r){//[l,r] [0, N-1]
	return (h[r+1]-(h[l]*h_base[r-l+1])%prime_mod+prime_mod)%prime_mod;
}

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		scanf("%s", str1);
		const int len1 = strlen(str1);
		hash_init(str1, len1);
		const int hash_of_str1 = get_hash(0, len1-1);
		scanf("%s", str2);
		const int len2 = strlen(str2);
		hash_init(str2, len2);
		int count = 0;
		for (int i = 0; i <= len2-len1; ++i){
			if(get_hash(i, i+len1-1) == hash_of_str1)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}