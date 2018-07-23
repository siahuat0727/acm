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

void solve(){
    int dis, n_horse;
    cin >> dis >> n_horse;
    double max_time = 0;
    for (int i = 0; i < n_horse; ++i){
        int s, v;
        cin >> s >> v;
        max_time = max(max_time,  (double)(dis-s)/v);
    }
    printf("%.6f\n", dis / max_time);
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
