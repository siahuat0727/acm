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
    int d;
    scanf("%d ", &d);
    int strength = 1;
    vector<int> v;
    int total_dmg = 0;
    int n_shoot = 0;
    char c;
    while((c=getchar()) != '\n'){
        if (c == 'C'){
            strength <<= 1;
        }else if(c == 'S'){
            v.PB(strength);
            total_dmg += strength;
            ++n_shoot;
        }else{
            putchar(c);
            puts(": sth wrong");
            exit(1);
        }
    }
    if(d < n_shoot){
        puts("IMPOSSIBLE");
        return;
    }
    int count = 0;
    while(d < total_dmg){
        int Max = *v.rbegin();
        for(auto it = v.begin(); it != v.end(); it++){
            if(*it == Max){
                *it >>= 1;
                total_dmg -= *it;
                break;
            }
        }
        ++count;
    }
    printf("%d\n", count);
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
