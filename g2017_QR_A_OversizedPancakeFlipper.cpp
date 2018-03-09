#include <cstdio>
#include <cstring>

int main(){
	int T;
	scanf("%d%*c", &T);
	for (int Case = 1; Case <= T; ++Case){
		int length = 0;
		bool b[1005];
		while(1){
			char c;
			scanf("%c", &c);
			if(c == '-')
				b[length] = false;
			else if(c == '+')
				b[length] = true;
			else
				break;
			++length;
		}
		int flipNum;
		scanf("%d%*c", &flipNum);
		const int end = length - flipNum + 1;
		int num = 0;
		for (int i = 0; i < end; ++i){
			if(!b[i]){
				for (int j = i; j < i+flipNum; ++j)
					b[j] = !b[j];
				++num;
			}
			// for (int k = 0; k < length; ++k)
			// 	printf("%d", b[k]);
			// printf("\n");
		}
		bool good = true;
		for (int i = end; i < length; ++i){
			if(!b[i])
				good = false;
		}
		printf("Case #%d: ", Case);
		if(good)
			printf("%d\n",num);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}