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

#define MAXN 10001

struct S{
    int m, n;
};

S s[MAXN];

#define ANY 200003
#define NOT 200004


int count(int n){
    bool lft_b = true;
    bool rgt_b = true;

    int lft = s[n].m, rgt = s[n].n;

    S s1 = {.m=lft, .n=ANY};
    S s2 = {.m=ANY, .n=lft};
   

    int i;
    for(i = n-1; i >= 0; --i){
        if(s1.m == NOT && s2.m == NOT)
            break;
        int l = s[i].m, r = s[i].n;

        if (l == s1.m){
            if (s1.n == ANY)
                s1.n = r;
            if (s1.n != r)
                s1.m = NOT;
        }else
            s1.m = NOT;

        if (r == s2.n){
            if (s2.m == ANY)
                s2.m = l;
            if (s2.m != l)
                s2.m = NOT;
        }else
            s2.m = NOT;
            
    }
    return n-i;
}

void solve(){
    int n;
    cin >> n;
    int d, a, b;
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d", &d, &a, &b);
        s[i].m = d + a;
        s[i].n = d - b;
        //printf("%d %d\n", s[i].m, s[i].n);
    }
    int max_pos = 1, num_valid = 1;
    int diff_x = 0;
    
    for(int i = 1; i < n; ++i){
        int pos = count(i);
        if (pos > max_pos){
            max_pos = pos;
            num_valid = 1;
        }else if(pos == max_pos)
            num_valid += 1;
    }
    printf("%d %d\n", max_pos, num_valid);

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
