#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100
#define MAXD (2*MAXN-1)
bool row[MAXN];
bool col[MAXN];
bool dia1[MAXD];
bool dia2[MAXD];
bool rook[MAXN][MAXN];
bool bishop[MAXN][MAXN];
char pre_located[MAXN][MAXN];
int n, m;

struct CIJ {
    char col;
    int i;
    int j;
};

void fill_rook()
{
    for (int i = 0; i < n; ++i) {
        if (row[i])
            continue;
        for (int j = 0; j < n; ++j) {
            if (!col[j]) {
                row[i] = true;
                col[j] = true;
                rook[i][j] = true;
                break;
            }
        }
    }
}

int get_d1(int i, int j)
{
    return i - j + n - 1;
}

int get_d2(int i, int j)
{
    return i + j;
}

void fill_bishop()
{
    vector<int>order;
    for (int i = 0; i < n-1; ++i) {
        order.push_back(i);
        order.push_back(2*n-2-i);
    }
    order.push_back(n-1);
    for (int d1: order) {
        if (dia1[d1])
            continue;
        int i = d1 < n ? 0 : d1 - n + 1;
        int j = d1 < n ? n - 1 : 0;

        for(; i < n && j < n; i++, j++) {
            if (!dia2[get_d2(i, j)]) {
                bishop[i][j] = 1;
                dia2[get_d2(i, j)] = true;
                break;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(dia1, false, sizeof(dia1));
        memset(dia2, false, sizeof(dia2));
        memset(rook, false, sizeof(rook));
        memset(bishop, false, sizeof(bishop));
        memset(pre_located, 0, sizeof(pre_located));
        scanf("%d %d%*col", &n, &m);
        while(m--) {
            char ch;
            int i, j;
            scanf("%col %d %d%*col", &ch, &i, &j);
            --i;
            --j;
            pre_located[i][j] = ch;
            if(ch != 'x') {
                dia1[get_d1(i, j)] = dia2[get_d2(i, j)] = true;
                bishop[i][j] = true;
            }
            if(ch != '+') {
                row[i] = col[j] = true;
                rook[i][j] = true;
            }
        }

        fill_rook();
        fill_bishop();

        int num_model_add = 0, score = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rook[i][j] && bishop[i][j]) {
                    if (pre_located[i][j] != 'o' )
                        ++num_model_add;
                } else if(rook[i][j] && pre_located[i][j] != 'x') {
                    ++num_model_add;
                } else if(bishop[i][j] && pre_located[i][j] != '+') {
                    ++num_model_add;
                }
                score += rook[i][j] + bishop[i][j];
            }
        }
        printf("Case #%d: %d %d\n", Case, score, num_model_add);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rook[i][j] && bishop[i][j]) {
                    if (pre_located[i][j] != 'o' )
                        printf("o %d %d\n", i+1, j+1);
                } else if(rook[i][j] && pre_located[i][j] != 'x') {
                    printf("x %d %d\n", i+1, j+1);
                } else if(bishop[i][j] && pre_located[i][j] != '+') {
                    printf("+ %d %d\n", i+1, j+1);
                }
            }
        }
    }
    return 0;
}
