#include <stdio.h>
#include <cstring>

int oneDigit(int n){
    if(n >= 10){
        int tmp = 0;
        tmp += n / 100;
        n %= 100;
        tmp += n / 10;
        n %= 10;
        tmp += n;
        return oneDigit(tmp);
    }else
        return n;
}

int main(){
    char str[30];
    while(gets(str) != NULL){
        int sum1 = 0;
        for (int i = 0; str[i] != '\0'; ++i){
            char c = str[i];
            c |= 1 << 5;
            if(c >= 'a' && c <= 'z'){
                sum1 += c - 'a' + 1;
            }
        }
        gets(str);
        int sum2 = 0;
        for (int i = 0; str[i] != '\0'; ++i){
            char c = str[i];
            c |= 1 << 5;
            if(c >= 'a' && c <= 'z')
                sum2 += c - 'a' + 1;
        }
        sum1 = oneDigit(sum1);
        sum2 = oneDigit(sum2);
        int Max, Min;
        if(sum1 > sum2){
            Max = sum1;
            Min = sum2;
        }else{
            Max = sum2;
            Min = sum1;
        }
        printf("%.2f ", (double)Min * 100 / Max);
        putchar('%');
        printf("\n");
    }

    return 0;
}