#include <cstdio>
#include <algorithm>
using namespace std;

struct road{
	int w, e;
};

road a[1000000];

long long cross;

bool cmp(road a, road b){
	return a.w == b.w ? a.e < b.e : a.w < b.w;
}

void combine(int l, int mid, int r){
	int i = l, j = mid + 1, cnt = 0;
	int buf[r - l + 1];
	while(i <= mid && j <= r){
		if(a[j].e < a[i].e){
			buf[cnt++] = a[j++].e;
			cross += mid - i + 1;
		}else
			buf[cnt++] = a[i++].e;
	}
	while(i <= mid) buf[cnt++]=a[i++].e;
	while(j <= r) buf[cnt++]=a[j++].e;

	for (int i = l; i <= r; ++i)
		a[i].e = buf[i - l];
}

void merge(int l, int r){
	if(l == r)
		return;
	const int mid = (l + r) >> 1;
	merge(l, mid);
	merge(mid + 1, r);
	combine(l, mid, r);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i){
		cross = 0;
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int j = 0; j < k; ++j)
			scanf("%d %d", &a[j].w, &a[j].e);
		sort(a, a + k, cmp);
		// printf("\n");
		// for (int i = 0; i < k; ++i)
		// 	printf("%d %d\n", a[i].w, a[i].e);
		merge(0, k-1);
		printf("Test case %d: %lld\n", i, cross);
	}
	return 0;
}