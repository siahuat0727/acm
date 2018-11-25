#include <stdio.h>

int arr[500000];
int buf[500000];
long long int step;

void combine(int l, int mid, int r){
	int i = l, j = mid+1, m = 0;
	while(i <= mid && j <= r){
		if(arr[i] < arr[j]){
			buf[m++] = arr[i++];
		}else{
			step += mid-i+1;
			buf[m++] = arr[j++];
		}
	}
	while(i <= mid)
		buf[m++] = arr[i++];
	while(j <= r)
		buf[m++] = arr[j++];
	for (int i = 0; i < m; ++i)
		arr[l+i] = buf[i];
}

void merge(int l, int r){
	if(l == r)
		return;
	int mid = (l+r)/2;
	merge(l, mid);
	merge(mid+1, r);
	combine(l, mid, r);
}

int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		step = 0;
		merge(0,n-1);
		printf("%lld\n", step);
	}
}