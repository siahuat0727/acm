#include <cstdio>
#define MAXN 21

int arr[MAXN];
bool vis[MAXN];
int n;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isPrime(int n){
	for (int k : prime)
		if (n == k)
			return true;
	return false;
}

void BT(int dimen){
	if(dimen == n){
		printf("1");
		for (int i = 1; i < n; ++i)
			printf(" %d", arr[i]);
		puts("");
		return;
	}
	for(int i = 2; i <= n; ++i){
		if(!vis[i]){
			if(isPrime(arr[dimen-1] + i)){
				if(dimen + 1 == n && !isPrime(arr[0] + i))
					continue;
				arr[dimen] = i;
				vis[i] = true;
				BT(dimen + 1);
				vis[i] = false;
			}
		}
	}
}

int main(){
	int case_ = 0;
	arr[0] = 1;
	while(scanf("%d", &n) != EOF){
		if(case_)
			puts("");
		printf("Case %d:\n", ++case_);
		BT(1);
	}
}
