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

#define MAXN 101

char waffle[MAXN][MAXN];
int raw_choc[MAXN];

int column_i_choc[MAXN];

int hcut[MAXN];
int vcut[MAXN];

int r, c;
int h, v;
int each_choc;
int each_raw_choc;
bool solved = false;

void BP(int n_hcut, int n_vcut){
    //printf("%d %d\n", n_hcut, n_vcut);
    if(n_hcut < h){
        int total_raw_choc = 0;
        for (int i = n_hcut==0 ? 0 : hcut[n_hcut-1]+1; i < r-1 && total_raw_choc <= each_raw_choc; ++i){
            total_raw_choc += raw_choc[i];
            if(total_raw_choc == each_raw_choc){
                hcut[n_hcut] = i;
                BP(n_hcut+1, n_vcut);
                    if(solved)
                        return;
            }
        }
    
    }
    else if (n_hcut == h && n_vcut < v){
        memset(column_i_choc, 0, sizeof(column_i_choc));
        for(int i = n_vcut==0 ? 0 : vcut[n_vcut-1]+1; i < c-1; ++i){
            int idx = 0;
            for(int j = 0; j < r; ++j){
                if(waffle[j][i] == '@'){
                    column_i_choc[idx]++;
                }
                if(j == hcut[idx])
                    idx++;
            }
            bool good = true;
            bool over = false;
            for(int k = 0; k < h+1; ++k){
                if(column_i_choc[k] < each_choc){
                    good = false;
                    break;
                }else if(column_i_choc[k] > each_choc){
                    over = true;
                    break;
                }
                
            }
            if(over)
                break;
            if(good)
                BP(n_hcut, n_vcut+1);
            if(solved)
                return;
        }
        
    }else if(n_hcut == h && n_vcut == v){
        solved = true;
        puts("POSSIBLE");
//        for(int i = 0; i < h; ++i)
//            printf("%d ",hcut[i]);
//        puts("");
//        for(int i = 0; i < v; ++i)
//            printf("%d ",vcut[i]);
//        puts("");
    }else{
        puts("err");
        exit(1);
    }
}

void solve(){
    solved = false;
    memset(raw_choc, 0, sizeof(raw_choc));
    scanf("%d%d%d%d\n", &r, &c, &h, &v);
    int total_choc = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            scanf("%c", &waffle[i][j]);
            if (waffle[i][j] == '@'){
                raw_choc[i]++;
                total_choc++;
            }
        }
        getchar();
    }
    if(total_choc % ((h+1)*(v+1))){
        puts("IMPOSSIBLE");
        return;
    }
    each_choc = total_choc / ((h+1)*(v+1));
    each_raw_choc = each_choc * (v+1);
    //printf("each choc = %d\teach_raw_choc = %d\n", each_choc, each_raw_choc);
    BP(0, 0);
    if(!solved)
        puts("IMPOSSIBLE");

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
