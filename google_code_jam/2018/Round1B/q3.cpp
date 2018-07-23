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

#define PB push_back
#define MAXN 10005
typedef unsigned long long int ll;
//ll ants[MAXN];
ll ans[MAXN];


using namespace std;


void solve(){
    int n;
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    int max_len = 0;
    for (int i = 0; i < n; ++i){
        int ant_w = 0;
        scanf("%d", &ant_w);
        //printf("ant %d\n", ant_w);
        for (int j = max_len; j >= 0; --j){
            ll total_w = ans[j] + (ll)ant_w;
            if (ans[j] <= ant_w*6){
                if(ans[j+1] != 0)
                    ans[j+1] = min(ans[j+1],total_w);
                else
                    ans[j+1] = total_w;
                max_len = max(max_len, j+1);
            }
            //printf("max %d, totol %llu, j %d\n", max_len, ans[j], j);
        }
    }
    printf("%d\n", max_len);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
