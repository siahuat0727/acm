#include <cstdio>
#include <cstring>
#include <cmath>

void readBigInt(char str[], int n[]){
	int length = strlen(str)-1;
	for (int i = 0; i < length; ++i){
		n[i] = str[length-i-1] - '0';
		// printf("qq %d %d\n", i, n[i]);
	}
	for (int i = length; i < 260; ++i){
		n[i] = 0;
	}
}

int main(){
	char  str[260];
	while(fgets(str, 260, stdin) != NULL){
		int x[260], y[260], z[510];
		for (int i = 0; i < 510; ++i)
			z[i] = 0;
		
		int xLength = strlen(str)-1;
		readBigInt(str, x);

		fgets(str, 260, stdin);
		int yLength = strlen(str)-1;
		readBigInt(str, y);

		// printf("qq xL yL y[0] %d %d %d\n", xLength, yLength, y[0]);
		if((xLength == 1 && x[0] == 0) || (yLength == 1 && y[0] == 0)){
			printf("0\n");
			continue;
		}
		int Max = 0;
		for (int i = 0; i < yLength; ++i){
			for (int j = 0; j < xLength; ++j){
				z[i+j] += x[j] * y[i];
				Max = i+j > Max ? i+j : Max;// =.=|||
			}
		}
		int digits;
		// printf("qq Max = %d\n", Max);
		
		for (int i = 0; i <= Max; ++i){
			// printf("qq i = %d\n", i);
			int cycle = z[i] == 0 ? 0 : (int)log10(z[i]);//log(0) is invalid!
			if(i == Max)
				digits = Max + cycle;
			while(cycle){//!!!!!!!!!!!!!!!!!
				// printf("qq cycle = %d\n", cycle);
				z[i+cycle] += z[i] / pow(10, cycle);
				z[i] %= (int)pow(10, cycle);
				--cycle;
			}
		}
		// printf("qq digits = %d\n", digits);
		for (int i = digits; i >= 0; --i)
			printf("%d", z[i]);
		puts("");
	}
	
	return 0;
}