#include <cstdio>
#include <cstring>
#include <cctype>
// void read(char c[1000][25], char str[], int length, int &num, bool &blank){
// 	if(!length){
// 		blank = true;
// 		return;
// 	}
// 	int i = 0;
// 	int j = 0;
// 	num = 0;
// 	while(1){
// 		if(i == length){
// 			if(j){
// 				c[num][j] = '\0';
// 				++num;
// 				j = 0;
// 			}
// 			break;
// 		}
// 		if(!isalnum(str[i])){
// 			if(j){
// 				c[num][j] = '\0';
// 				++num;
// 				j = 0;
// 			}
// 		}else{
// 			c[num][j] = str[i];
// 			++j;
// 		}
// 		++i;
// 	}
// }

void notAlnumToSpace(char str[], int length){
	for (int i = 0; i < length; ++i)
		if(!isalnum(str[i]))
			str[i] = ' ';
}

int main(){
	char str[1010];
	int T = 0;
	while(gets(str) != NULL){
		printf("%2d. ", ++T);
		bool blank = false;
		if(!strlen(str))
			blank = true;
		char a[1000][25];
		int length = strlen(str);
		notAlnumToSpace(str, length);

		int aNum = 0;
		char delim[] = " ";
		char *token;
		token = strtok(str, delim);
		while(token != NULL){
			strcpy(a[aNum++], token);
			// printf("%s\n", a[aNum-1]);
			token = strtok(NULL, delim);
		}
		// read(a, str, length, aNum, blank);

		gets(str);
		if(!strlen(str))
			blank = true;
		if(blank){
			printf("Blank!\n");
			continue;
		}

		char b[1000][25];
		length = strlen(str);
		notAlnumToSpace(str, length);
		int bNum = 0;
		
		token = strtok(str, delim);
		while(token != NULL){
			strcpy(b[bNum++], token);
			token = strtok(NULL, delim);
		}


		// read(b, str, length, bNum, blank);
		// printf("aNum bNum %d %d\n", aNum, bNum);
		int LCS[aNum+5][bNum+5];
		for (int i = 0; i <= aNum; ++i)
			LCS[i][0] = 0;
		for (int i = 1; i <= bNum; ++i)
			LCS[0][i] = 0;
		for (int i = 1; i <= aNum; ++i){
			for (int j = 1; j <= bNum; ++j){
				if(strcmp(a[i-1], b[j-1]) == 0)
					LCS[i][j] = LCS[i-1][j-1] + 1;
				else{
					if(LCS[i-1][j] >= LCS[i][j-1]){
						LCS[i][j] = LCS[i-1][j];
					}else{
						LCS[i][j] = LCS[i][j-1];
					}
				}
			}
		}
		// for (int i = 0; i <= aNum; ++i){
		// 	for (int j = 0; j <= bNum; ++j)
		// 	{
		// 		printf("%2d ", LCS[i][j]);
		// 	}
		// 	puts("");
		// }
		printf("Length of longest match: %d\n", LCS[aNum][bNum]);
	}
}