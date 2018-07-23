#include <cstdio>
#include <cstring>

#define MAXN 1000
bool b[MAXN];
bool flip[MAXN];

bool isOdd(int n)
{
    return n & 1;
}

int main()
{
    int T;
    scanf("%d%*c", &T);
    for (int Case = 1; Case <= T; ++Case) {
        int length = 0;
        memset(b, 0, sizeof(b));
        memset(flip, 0, sizeof(flip));
        while (1) {
            char c = getchar();
            if (c == '-')
                b[length] = false;
            else if (c == '+')
                b[length] = true;
            else
                break;
            ++length;
        }
        int k;
        scanf("%d%*c", &k);
        const int end = length - k + 1;
        int num_filp = 0;
        int num_owe = 0;
        for (int i = 0; i < end; ++i) {
            if (i >= k && flip[i - k])
                --num_owe;
            if (!b[i] && !isOdd(num_owe) || b[i] && isOdd(num_owe)) {
                flip[i] = true;
                ++num_owe;
                ++num_filp;
            }
        }
        bool bad = false;
        for (int i = end; i < length; ++i) {
            if (i >= k && flip[i - k])
                --num_owe;
            if (!b[i] && !isOdd(num_owe) || b[i] && isOdd(num_owe))
                bad = true;
        }
        printf("Case #%d: ", Case);
        if (bad)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", num_filp);
    }
    return 0;
}
