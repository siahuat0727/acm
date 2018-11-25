#include <cstdio>
#include <cstring>

int main(){
	int n;
	int T = 0;
	while(scanf("%d%*c", &n) && n){
		char str[n+5];
		gets(str);
		printf("Test case #%d\n", ++T);
		for (int length = 2; length <= n; ++length){
			bool same = false;
			int i; // i for longest period
			int num; // num for # of repeat
			for (i = 1; i <= length/2; ++i){
				if(length % i != 0)
					continue;
				num = length / i;
				bool sub_same = true;
				for (int j = 1; j < num; ++j){
					if(sub_same == false)
						break;
					int start = i*j;
					for (int k = 0; k < i; ++k)
						if(str[k] != str[start+k])
							sub_same = false;
				}
				if(sub_same){
					same = true;
					break;
				}
			}
			if(same)
				printf("%d %d\n", length, num);
		}
		putchar('\n');
	}
	return 0;
}