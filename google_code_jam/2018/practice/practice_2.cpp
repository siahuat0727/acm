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

#define MAXN 27

int party[MAXN];
int ppl_left;
int n;

inline bool some_inside(){
    return ppl_left != 0;
}

int find_max(){
    int Max = -1;
    int Index = -1;
    for(int i = 0; i < n; ++i)
        if(Max < party[i]){
            Max = party[i];
            Index = i;
        }
    --party[Index];
    --ppl_left;
    return Index;
}

void find_ppl(int& first, int& second){
    first = find_max();
    if (some_inside() && ppl_left != 2)
        second = find_max();
}

void let_ppl_out(){
    int first = -1;
    int second = -1;
    find_ppl(first, second);
    printf(" %c", (char)(first+'A'));
    if(second != -1)
        putchar((char)(second+'A'));
}

void solve(){
    cin >> n;
    ppl_left = 0;
    for (int i = 0; i < n; ++i){
        cin >> party[i];
        ppl_left += party[i];
    }
    while(some_inside())
        let_ppl_out();
    puts("");
}
	
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
