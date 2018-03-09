#include <cstdio>

int main(){
	int arr[1005];
	int LIS[1005];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	int Max = 1;
	for (int i = 0; i < N; ++i){
		LIS[i] = 1;
		for (int j = 0; j < i; ++j)
			if(arr[j] < arr[i] && LIS[j] >= LIS[i]){
				LIS[i] = LIS[j] + 1;
				Max = LIS[i] > Max ? LIS[i] : Max;
			}
	}
	printf("%d\n", Max);
	return 0;
}