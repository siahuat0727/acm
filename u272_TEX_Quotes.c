#include <stdio.h>
#include <stdbool.h>

int main(){
	char c;
	bool right = true;
	while((c = getchar()) != EOF){
		if(c == '"'){
			printf("%s", right ? "``" : "''");
			right = !right;
		}else
			putchar(c);
	}
	return 0;
}