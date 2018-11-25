#include <cstdio>

using namespace std;

inline bool is_equal_3(int num[]){
    return num[0] == num[1] && num[1] == num[2];
}

inline int find_smallest_index_3(int num[]){
    return num[0] < num[1] ? (num[0] < num[2] ? 0 : 2) : num[1] < num[2] ? 1 : 2;
}

int main(){
    const int mod_num[] = {23, 28, 33};
    int num[3], d;
    int Case = 0;
    while(scanf("%d%d%d%d", &num[0], &num[1], &num[2], &d) && ~num[0]){
        for (int j = 0; j < 3; ++j)
            num[j] %= mod_num[j];
        while(!is_equal_3(num)){
            int idx = find_smallest_index_3(num);
            num[idx] += mod_num[idx];
        }
        int ans = num[0] - d;
        ans += ans <= 0 ? 21252 : 0;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++Case, ans);
    }
    return 0;
}
