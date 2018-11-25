#include <cstdio>
#include <cstring>

#define MAXN 500001

int arr[MAXN];
int buf[MAXN];
long long int n_swap;

void combine(int s, int t, int mid){
	int l = s;
	int r = mid + 1;
	int idx = 0;
	while(l <= mid && r <= t){
		if(arr[l] <= arr[r])
			buf[idx++] = arr[l++];
		else{
			n_swap += mid - l + 1; 
			buf[idx++] = arr[r++];
		}
	}
	while(l <= mid)
		buf[idx++] = arr[l++];
	while(r <= t)
		buf[idx++] = arr[r++];
	memcpy(arr+s, buf, (t-s+1)*sizeof(int));
}

void mergeSort(int s, int t){
	if (s >= t)
		return;
	int mid = (s+t) >> 1;
	mergeSort(s, mid);
	mergeSort(mid+1, t);
	combine(s, t, mid);
}

int main(){
	int n;
	while(scanf("%d", &n) && n){
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		n_swap = 0;
		mergeSort(0, n-1);
		printf("%lld\n", n_swap);
	}
}
