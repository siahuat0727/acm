#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    string str;
    int index = 0;
    int Case = T;
    while(T--){
        int a, b, n;
        cin >> a >> b >> n;
        int low = a;
        int high = b+1;
        string all_str = "";
        while(1){
            ++index;
            int guess = (low+high)>>1;
            cout << guess << endl;;
            cin >> str;
            if(str == "TOO_BIG")
                high = guess;
            else if(str == "TOO_SMALL")
                low = guess;
            else if(str == "CORRECT")
                break;
            else{
                fprintf(stderr, "wrong ans: %s\n", all_str.c_str());
                exit(1);
            }
        }
    }
    return 0;
}
