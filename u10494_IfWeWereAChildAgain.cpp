#include <cstdio>
#include <cstring>
#define N 1000

int main(){
	char str[N];
	while(scanf("%s", &str) != EOF){
		char oprt;
		while(scanf("%c", &oprt) && oprt == ' ');
		int b;
		scanf("%d", &b);
		long long int a[N];

		const int length = strlen(str);
		for (int i = 0; i < length; ++i)
			a[length - i - 1] = str[i] - '0';
		for (int i = length; i < N; ++i)
			a[i] = 0;

		int c[N];
		for (int i = length - 1; i > 0; --i){
			c[i] = a[i] / b;
			a[i - 1] += (a[i] % b)*10;
		}
		c[0] = a[0] / b;
		const int mod = a[0] % b;

		if(oprt == '/'){
			int tmp = length - 1;
			while(!c[tmp] && tmp > 0)
				--tmp;
			for (int i = tmp; i >= 0; --i)
				printf("%d", c[i]);
		}else
			printf("%d", mod);
		printf("\n");
	}
	return 0;
}