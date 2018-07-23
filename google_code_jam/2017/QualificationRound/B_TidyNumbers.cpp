#include <cstdio>
#include <cstring>

int main()
{
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        char cnum[20];
        scanf("%s", cnum);
        const int length = strlen(cnum);
        while (1) {
            bool change = false;
            for (int i = 0; i < length - 1; ++i) {
                if (cnum[i] > cnum[i + 1]) {
                    --cnum[i];
                    for (int j = i + 1; j < length; ++j)
                        cnum[j] = '9';
                    change = true;
                }
            }
            if (!change)
                break;
        }
        printf("Case #%d: ", Case);
        for (int i = 0; i < length; ++i)
            if (cnum[i] != '0')
                putchar(cnum[i]);
        putchar('\n');
    }
    return 0;
}
