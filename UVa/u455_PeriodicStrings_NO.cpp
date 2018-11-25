#include <cstdio>
#include <cstring>

int main(){
	int n;
	scanf("%d%*c", &n);
	char str[100];
	while(n--){
		getchar();
		scanf("%s", str);
		const int length = strlen(str);
		bool same = false;
		int i;
		for (i = 1; i <= length/2; ++i){
			if(length % i != 0)
				continue;
			const int num = length / i;
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
			printf("%d\n", i);
		else
			printf("%d\n", length);
		if(n)
			putchar('\n');
	}
	return 0;
}