#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x3fff3fff
#define MAXN 101

int food[MAXN];
int energy[MAXN];
vector<int> Vp[MAXN];
bool inqueue[MAXN];

bool SPFA(int src, int dest){
	memset(energy, -1, sizeof(energy));
	memset(inqueue, false, sizeof(inqueue));
	
	energy[src] = 100;
	inqueue[src] = true;
	queue<int> Q;
	Q.push(src);
	while(!Q.empty()){
		int now = Q.front();
		inqueue[now] = false;
		Q.pop();
		//cout << "now = " << now << " energy = " << energy[now];
		for (int nxt : Vp[now]){
			int nxt_energy = energy[now] + food[nxt];
			if(nxt_energy > 0 && nxt_energy > energy[nxt]){
				if(nxt == dest){
		//			cout << " reach dest with energy = " << nxt_energy << endl;
					return true;
				}
				energy[nxt] = nxt_energy;
		//		cout << ", can go " << nxt << " energy = " << nxt_energy;
				if(!inqueue[nxt]){
					Q.push(nxt);
					inqueue[nxt] = true;
				}
			}
		}
		//cout << endl;
	}
	return false;
}


int main(){
	int n;
	while (cin >> n && n != -1){
		for(int i = 1; i <= n; ++i){
			Vp[i].clear();
			cin >> food[i];
			int t;
			cin >> t;
			while(t--){
				int can_reach;
				cin >> can_reach;
				Vp[i].push_back(can_reach);
			}	
		}
		if(SPFA(1, n))
			puts("winnable");
		else
			puts("hopeless");
	}
	return 0;
}
