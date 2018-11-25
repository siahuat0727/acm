#include <cstdio>

int main(){
	int arr[1001];
	int size;
	while(scanf("%d", &size) != EOF){
		int step = 0;
		for (int i = 0; i < size; ++i)
			scanf("%d", &arr[i]);
		for(int i=1;i<size;i++){
			int tmp=arr[i];
			int j;
			for(j=i-1;j>=0;j--){
				if(arr[j]>tmp) {
					arr[j+1]=arr[j];
					step++;
				}
				else 
					break;
			}
			arr[j+1]=tmp;
		}
		printf("Minimum exchange operations : %d\n", step);
	}
	return 0;	
}