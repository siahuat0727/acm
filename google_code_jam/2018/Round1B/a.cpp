#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAXN 10001

typedef long double ld;

struct voter {
    int c;
    int need;
} num_voter[MAXN];

using namespace std;

bool cmp1(voter a, voter b) {
    return a.c < b.c;
}

bool cmp2(voter a, voter b) {
    return a.need < b.need;
}

void solve(){
    int n, l;
    scanf("%d %d\n", &n, &l);
    int n_left = n;
    memset(num_voter, 0, sizeof(num_voter));
    for (int i = 0; i < l; ++i) {
        scanf("%d", &num_voter[i].c);
        n_left -= num_voter[i].c;
    }
    const ld each_percent = 100.00/n;
    int num_need = 0;
    ld percent = 0;
    while (round(percent) <= percent && num_need < n) {
        percent += each_percent;
        num_need++;
    }
    sort(num_voter, num_voter+l, cmp1);

    for (int i = 0; i < l; ++i) {
        ld cur = each_percent * num_voter[i].c;
        if (round(cur) > cur) {
            continue;
        }
        if (i != 0 && num_voter[i].c <= num_voter[i-1].c+num_voter[i-1].need) {
            num_voter[i].need = num_voter[i-1].c + num_voter[i-1].need - num_voter[i].c;
            continue;
        }
        while (num_voter[i].need < num_need) {
            ld d = each_percent * (num_voter[i].c + num_voter[i].need);
            if (round(d) > d)
                break;
            num_voter[i].need++;
        }
    }
    sort(num_voter, num_voter+l, cmp2);
    int total_percent = 0;
    for (int i = 0; i < l; ++i) {
        if (n_left > 0) {
            if (num_voter[i].need < num_need) {
                int Min = min(num_voter[i].need, n_left);
                total_percent += lround(each_percent * (num_voter[i].c + Min));
                n_left -= Min;
            } else {
                int Min = min(num_need, n_left);
                total_percent += lround(each_percent * num_voter[i].c);
                total_percent += lround(each_percent * Min);
                n_left -= Min;
            }
        } else {
            total_percent += lround(each_percent * num_voter[i].c);
        }
    }
    while (n_left > 0) {
        int Min = min(num_need, n_left);
        total_percent += lround(each_percent * Min);
        n_left -= Min;
    }
    printf("%d\n", total_percent);
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
