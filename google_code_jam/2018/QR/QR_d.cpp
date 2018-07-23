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
    double a;
    scanf("%lf", &a);
    if (a <= 1.414213){
        double n = a/2;
        double x1 = (sqrt(0.5 - n*n) + n) / 2;
        double y1 = sqrt(0.25 - x1*x1);
        double x2 = y1 == 0 ? y1 : -y1;
        double y2 = x1;
        printf("%g %g %g\n", x1, y1, 0.0);
        printf("%g %g %g\n", x2, y2, 0.0);
        printf("%g %g %g\n", 0.0, 0.0, 0.5);
    }else{
        
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}
