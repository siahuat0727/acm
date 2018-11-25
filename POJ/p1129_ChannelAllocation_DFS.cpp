#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define PB push_back
#define MAXN 26
#define INF 0x3f3f3f3f


int channel[MAXN];
using namespace std;

vector<int> V[MAXN];
int MIN_CHN;
int N;

void DFS(int k, int total_chn){
	if(k >= N){
		MIN_CHN = min(MIN_CHN, total_chn);
		return;
	}

	int nxt = k+1;
	for (int chn = 1; chn <= total_chn; ++chn){
		bool can_use = true;
		// for (int i : V[k]){ poj not support =.=
		for (vector<int>::iterator it = V[k].begin(); it != V[k].end(); ++it){
			if(channel[*it] == chn){
				can_use = false;
				break;
			}
		}
		if (can_use){
			channel[k] = chn;
			DFS(nxt, total_chn);
			channel[k] = 0;
		}
	}

	channel[k] = total_chn+1;
	DFS(nxt, total_chn+1);
	channel[k] = 0;

}

int main(){
	while(scanf("%d\n", &N) && N){
		MIN_CHN = INF;
		memset(channel, 0, sizeof(channel));
		for (int i = 0; i < N; ++i)
			V[i].clear();
		for (int i = 0; i < N; ++i){
			char str[MAXN+2];
			scanf("%s", str);
			int src = str[0] - 'A';
			int len = strlen(str);
			for (int j = 2; j < len; ++j){	
				V[src].PB(str[j] - 'A');
			}
		}
		DFS(0, 1);
		printf("%d channel%s needed.\n", MIN_CHN, MIN_CHN == 1 ? "" : "s");
	}
}
