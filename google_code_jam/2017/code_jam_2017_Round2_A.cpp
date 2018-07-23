#include <cstdio>
#include <algorithm>

#define MAXN 101
#define MAXP 4

using namespace std;

int solve(){
    int n, p;
    scanf("%d%d", &n, &p);
    int mod_p[MAXP] = {0};
    while(n--){
        int num;
        scanf("%d", &num);
        ++mod_p[num%p];
    }
    int ans = mod_p[0];
    for (int i = 1; i <= p/2; ++i){
        if(i<<1 == p){ 
            // p/2 p/2
            ans += mod_p[i] >> 1;
            mod_p[i] &= 1;
        }
        else{
            // i p-i
            int min_ = min(mod_p[i], mod_p[p-i]);
            mod_p[i] -= min_;
            mod_p[p-i] -= min_;
            ans += min_;
        }
    }

    if (p == 4){
        // 1 1 2
        int min_ = min(mod_p[1]>>1, mod_p[2]);
        mod_p[1] -= min_ << 1;
        mod_p[2] -= min_;
        ans += min_;
    }

    // i i ... i p time
    for (int i = 1; i < p; ++i){
        ans += mod_p[i] / p;
        mod_p[i] %= p;
    }

    bool sth_left = false;
    for (int i = 1; i < p; ++i)
        if(mod_p[i])
            sth_left = true;
    return sth_left ? ans + 1 : ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %d\n", i, solve());
}
