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

struct Adjust{
    int Min;
    double Max;
};

vector<Adjust> v;
vector<Adjust> v_all;

bool cmp(Adjust a, Adjust b){
    return a.Min == b.Min ? a.Max < b.Max : a.Min < b.Min;
}

void vec_merge_front(auto it){
    if(it != v.begin() && (it-1)->Max > it->Min){
        it->Min = min((it-1)->Min, it->Min);
        v.erase(it-1);
    }
}

void vec_merge_back(auto it){
    if(it+1 != v.end() && (it+1)->Min < it->Max){
        it->Max = max((it+1)->Max, it->Max);
        v.erase(it+1);
    }
}

void vec_insert(Adjust a){
    auto it = lower_bound(v.begin(), v.end(), a, cmp); // the back one
    it = v.insert(it, a);
    vec_merge_back(it);
    vec_merge_front(it);
}

void vec_add_all(Adjust a){

}

void solve(){
    v.clear();
    Adjust s0 = {0,0};
    v.PB(s0);
    int n;
    int p;
    scanf("%d%d", &n, &p);
    int total = 0;
    while(n--){
        int w, h;
        scanf("%d %d", &w, &h);
        Adjust a = {2*( min(w, h)), 2*( sqrt(w*w + h*h))};
        total += 2*(w + h);

        v_all.clear();
        for (Adjust b : v){
            Adjust tmp = {b.Min + a.Min, b.Max + a.Max};
            if (tmp.Min <= p-total)
                v_all.PB(tmp);
        }
        for (Adjust b : v_all){
            vec_insert(b);
        }
    }
    Adjust prev = {0, 0};
    for (Adjust b : v) {
        if (b.Min > p-total) {
            break;
        }
        prev = b;
    }
    if (prev.Max + total < p) {
        printf("%.6f\n", total+prev.Max);
    } else {
        printf("%.6f\n", (double)p);
    }

}

void test(){
    Adjust a = {1, 3};
    Adjust b = {2, 9};
    Adjust c = {4, 8}; // 4 5
    v.PB(a);
    v.PB(c);
    vec_insert(b);
    for (Adjust a : v){
        printf("%d %f\n", a.Min, a.Max);
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
