#include <cstdio>
#include <cstring>
#include <algorithm>

#define PB push_back

using namespace std;

#define MAXN 100001

struct Candidate {
    int M, N, start, xstart;
};

int M[MAXN];
int N[MAXN];
Candidate M_candidate[MAXN];
Candidate N_candidate[MAXN];

const Candidate EmptyStruct = {0};

void solve(){
    int n;
    scanf("%d", &n);
    int d, a, b;
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d", &d, &a, &b);
        M[i] = d + a;
        N[i] = d - b;
    }

    M_candidate[0] = EmptyStruct;
    N_candidate[0] = EmptyStruct;
    M_candidate[0].M = M[0];
    N_candidate[0].N = N[0];

    int largest_set = 0;
    int num_set = 0;
    if (n == 1)
        largest_set = num_set = 1;
    for (int i = 1; i < n; ++i) {
        // for M-candidate
        if (M[i] == M[i-1]) {
            M_candidate[i] = M_candidate[i-1];
        } else if (M[i] == N_candidate[i-1].M) {
            M_candidate[i] = N_candidate[i-1];
            M_candidate[i].xstart = i;
        } else {
            M_candidate[i] = N_candidate[i-1];
            M_candidate[i].M = M[i];
            M_candidate[i].start = M_candidate[i].xstart;
            M_candidate[i].xstart = i;
        }
        // for N-candidate
        if (N[i] == N[i-1]) {
            N_candidate[i] = N_candidate[i-1];
        } else if (N[i] == M_candidate[i-1].N) {
            N_candidate[i] = M_candidate[i-1];
            N_candidate[i].xstart = i;
        } else {
            N_candidate[i] = M_candidate[i-1];
            N_candidate[i].N = N[i];
            N_candidate[i].start = N_candidate[i].xstart;
            N_candidate[i].xstart = i;
        }
        int Max = max(i - N_candidate[i].start+1, i - M_candidate[i].start+1);
        if (largest_set < Max) {
            largest_set = Max;
            num_set = 0;
        }
        num_set += largest_set == Max;
    }
    printf("%d %d\n", largest_set, num_set);
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
