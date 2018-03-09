// #include <stdio.h>
// #include <stdbool.h>
// int nextUglyNum(){
// 	static int temp, ugly = 1;
// 	static bool noAnyFactor;
// 	static const int factor[] = {2, 3, 5};
// 	for (;;ugly++){
// 		if(ugly % 7 == 0 || ugly % 11 == 0 || ugly % 13 == 0 || ugly % 17 == 0 || ugly % 23 == 0 || ugly % 31 == 0 || ugly % 37 == 0)
// 			continue;
// 		temp = ugly;
// 		noAnyFactor = true;
// 		if(ugly == 1)
// 			return ugly++;
// 		for (int i = 0; i < 3; ++i)
// 			if(temp % factor[i] == 0)
// 				noAnyFactor = false;
// 		if(noAnyFactor)
// 			continue;
// 		for (int i = 0; i < 3; ++i)
// 			while(temp % factor[i] == 0)
// 				temp /= factor[i];
// 		if(temp == 1)
// 			return ugly++;
// 	}
// }

// int main(){
// 	for (int i = 1; i < 1500; ++i)
// 		nextUglyNum();
// 	printf("The 1500'th ugly number is %d.\n", nextUglyNum());	
// 	return 0;
// }

#include <stdio.h>
#include <limits.h>
// #define MIN(x, y, z) (x<y && x<z ? x : y<z ? y : z)
#define MIN(x, y) ((x)<(y) ? (x) : (y))


int main(){
	int ugly[1501] = {0, 1};
	int factor[3] = {2, 3, 5};
	int index[3] = {0};
	for (int i = 2; i <= 1500; ++i){
		for (int j = 0; j < 3; ++j)
			while(ugly[index[j]] * factor[j] <= ugly[i-1])
				index[j]++;
		int min = INT_MAX;
		for (int i = 0; i < 3; ++i)
			min = MIN(min, ugly[index[i]]*factor[i]);
		ugly[i] = min;
	}
	printf("The 1500'th ugly number is %d.\n", ugly[1500]);	
	return 0;
}