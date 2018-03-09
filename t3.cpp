#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int coin[26];

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(coin, 0, sizeof coin);
		int m;
		cin >> m;
		while(m--){
			char c;
			cin >> c;
			int index = c - 'A';
			int t;
			cin >> t;
			coin[index] += t;
		}
		int total = 0;
		for (int i = 0; i < 26; ++i){
			while(coin[i] >= 3)
				coin[i] = coin[i] / 3 + coin[i] % 3;
			total += coin[i];
		}
		cout << total << endl;
	}
	return 0;
}