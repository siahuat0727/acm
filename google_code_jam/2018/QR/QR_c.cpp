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
#include <ctime>

using namespace std;
#define my_print(arg) fprintf(fp, arg)
#define my_print2(arg1, arg2) fprintf(fp, arg1, arg2)
#define my_print3(arg1, arg2, arg3) fprintf(fp, arg1, arg2, arg3)

#define MAXN 1001
bool ground[MAXN][MAXN];
int T;
int idx = 0;
bool solve(){
    srand(time(0));
    memset(ground, 0, sizeof(ground));
    int a;
    scanf("%d", &a);
    int x, y;
    puts("500 500");
    fflush(stdout);
    int u,d,l,r;
    u = d = l = r = 500;
    ground[500][500] = true;
    int n_try = 0;
    while(scanf("%d %d", &x, &y)==2 && !(x==0 && y == 0) && !(x==-1 && y == -1)){
        ground[x][y] = true;
        d = min(d, y);
        u = max(u, y);
        l = min(l, x);
        r = max(r, x);
        int width = r-l+1;
        int height = u-d+1;
        int rec_area = width * height;
        if (rec_area >= a){
            for(int i = l; i <= r; ++i){
                for(int j = u; j >= d; --j){
                    if (ground[i][j] == false){
                        x = i == l ? i+1 : i == r ? i - 1 : i;
                        y = j == d ? j+1 : j == u ? j - 1 : j;
                    }
                }
            }
        }
        printf("%d %d\n", x, y);
        fflush(stdout);
    }
    if(x == -1)
        return false;
    return true;

}
	
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        if(!solve())
            break;
    }
    return 0;
}
