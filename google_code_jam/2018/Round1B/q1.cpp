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

#define MAXN 2005
#define MAXL 11

char str[MAXN][MAXL];
int n, l;

using namespace std;

char ans[MAXL];
int total[MAXL];

bool solved;

void bt(int k){
    if(k == l){
        for (int i = 0; i < n; ++i){
            if (strcmp(ans, str[i]) == 0){
                return;
            }
        }
        puts(ans);
        solved = true;
        return;
    }
    for (int i = 0; i < n; ++i){
        ans[k] = str[i][k];
        bt(k+1);
        if(solved)
            return;
    }
}

void solve(){
    solved = false;
    memset(ans, 0, sizeof(ans));
    scanf("%d%d\n", &n, &l);
    for(int i = 0; i < n; ++i)
        scanf("%s\n", str[i]);


    bt(0);
    if(!solved)
        puts("-");
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
