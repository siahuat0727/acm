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

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v;
    vector <int> v1;
    vector <int> v2;
    for (int i = 0; i < n; ++i){
        int t;
        scanf("%d", &t);
        v.PB(t);
        if (i & 1)
            v2.PB(t);
        else
            v1.PB(t);
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    int idx = 0;
    bool ok = true;
    for (auto it = v.begin(); it != v.end(); ++it, ++idx){
        int k;
        if (idx & 1){
            k = *(it2++);
        }else{
            k = *(it1++);
        }
        if (*it != k){
            ok = false;
            break;
        }
    }
    if (ok){
        puts("OK");
    }else{
        printf("%d\n", idx);
    }
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
