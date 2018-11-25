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

using namespace std;

#define PB push_back
#define MAXN 10001

int square[101];
int dp[MAXN];
int ans[MAXN];

int main() {
    for (int i = 1; i <= 100; ++i)
    	square[i] = i*i;
    for (int i = 1; i < MAXN; ++i){
    	memset(dp, 0, sizeof dp);
    	dp[0] = 1;
    	int count = 0;
    	while(!ans[i]){
    		++count;
    		for(int j = i-1; j >= 0; --j){
    			if(dp[j]){
    				for(int k = 1; k <= 100; ++k){
    					int temp = j+square[k];
    					if(temp >= i){
	    					if(temp == i)
	    						ans[i] = count;
    						break;
    					}
    					dp[temp] = 1;
    				}
    			}
    			if(ans[i])
    				break;
    		}
    	}
    }
    int T;
    cin >> T;
	while(T--){
		int t;
		cin >> t;
		cout << ans[t] << endl;
	}
    return 0;
}
