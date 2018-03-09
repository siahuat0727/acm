#include <cstdio>
#include <cstring>

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
	int n;
	int T = 0;
	while(scanf("%d%*c", &n) && n){
		char str[n+5];
		int pi[n+5];
		gets(str);
		KMP_fail(str ,pi);
		printf("Test case #%d\n", ++T);
		for (int length = 2; length <= n; ++length){
			int period = length - (pi[length-1] + 1);
			// printf("p = %d\n", period);
			if(!(length % period) && period != length)
				printf("%d %d\n", length, length / period);
		}
		putchar('\n');
	}
	return 0;
}