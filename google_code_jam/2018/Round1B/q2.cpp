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

using namespace std;

#define MAXN 201

int flavor[MAXN];
bool sold[MAXN];

void solve(){
    memset(flavor, 0, sizeof(flavor));
    memset(sold, 0, sizeof(sold));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int min_like = 0x3fffffff;
        int min_fav = -1;
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; ++j){
            int d;
            scanf("%d", &d);
            fprintf(stderr, "read %d\n", d);

            if(!sold[d] && min_like > ++flavor[d]){
                min_fav = d;
                min_like = flavor[d];
            }
        }
        printf("%d\n", min_fav);
        fflush(stdout);
        if (min_fav != -1)
            sold[min_fav] = true;
    }



}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
}
