#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int arr[10];

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(arr, 0, sizeof arr);
		int m, n;
		cin >> m >> n;
		while(m--){
			int t;
			cin >> t;
			arr[t]++; 
		}
		while(n--){
			int t;
			cin >> t;
			arr[t]++; 
		}
		int total = 0, same = 0;
		for (int i = 0; i < 10; ++i)
			switch(arr[i]){
				case 2: same++;
				case 1: total++;
			}
		cout << (double)same/total > 0.5 << endl;
	}
}