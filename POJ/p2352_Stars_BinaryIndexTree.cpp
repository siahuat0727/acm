#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>

#define MAXN 32005

using namespace std;
int v[MAXN];
int s[MAXN];
int arr[MAXN];


int lowbit(int n){
	return n & (-n);
}

int getSum(int index){
	int ans = 0;
	while(index > 0){
		ans += s[index];
		index -= lowbit(index);
	}
	return ans;
}

void modify(int index, int delta){
	for(int i = index; i < MAXN; i+=lowbit(i))
		s[i] += delta;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
    	int x, y;
        scanf("%d%d", &x, &y);
        x++;
        modify(x, 1);
        arr[getSum(x)]++;
    }
    for (int i = 1; i <= T; ++i){
    	// int ans = getSum(i);
    	// printf("%d\n", ans - last);
    	// last = ans;
    	printf("%d\n", arr[i]);
    }
    return 0;
}
