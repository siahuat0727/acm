#include <cstdio>
#include <cstring>

int main(){
	char a[200010];
	while(gets(a) != NULL){
		char b[100005];
		const int length = strlen(a);
		for (int i = 0; i < length; ++i)
			b[i] = a[length - i - 1];
		b[length] = '\0';
		for (int i = length; i >= 0; --i){
			if(strncmp(a+length-i, b, i) == 0){
				strcat(a, b+i);
				break;
			}
		}
		printf("%s\n", a);
	}
	return 0;
}