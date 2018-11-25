#include <cstdio>
#include <cstring>
#define N 100000000
char str[N];
int pi[N];
inline void KMP_fail (char *B, int *pi){
	int len = strlen(B);
	pi[0] = -1;
	for (int i = 1, cur_pos = -1; i < len; ++i){
		while(~cur_pos && B[i] != B[cur_pos+1])
			cur_pos = pi[cur_pos];
		if(B[i] == B[cur_pos+1])
			++cur_pos;
		pi[i] = cur_pos;
	}
	// return cur_pos to find period(the lasr of pi)
}

int main(){
	while(gets(str)!=NULL && str[0]!='.'){
		KMP_fail(str ,pi);
		int n = strlen(str);
		int period = n - (pi[n-1] + 1);
		if(!(n % period) && period != n)
			printf("%d\n", n / period);
		else
			printf("1\n");
	}
	return 0;
}