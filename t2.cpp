#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int card[13];

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(card, 0, sizeof card);
		for (int i = 0; i < 6; ++i){
			int t;
			cin >> t;
			card[t]++;
		}
		int two = 0, three = 0, four = 0;
		for (int i = 0; i < 13; ++i){
			switch(card[i]){
				case 2: ; two++; break;
				case 3: ; three++; break;
				case 4: ; four++; break;
			}
		}
		cout << (three && two ? "full house" : four && two ? "tiki pair" : four ? "tiki" : three == 2 ? "two triples" : three ? "one triple" : two == 3 ? "three pairs" : two == 2 ? "two pairs" : two ? "one pair" : "single" )<< endl;
	}
	return 0;
}