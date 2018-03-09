#include <cstdio>
#include <cstring>

int main(){
	char str[1000005];
	while(gets(str) && str[0]!='.'){
		const int length = strlen(str);
		bool same = false;
		int i;
		int num;
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
			printf("%d\n", num);
		else
			printf("%d\n", 1);
	}
	return 0;
}