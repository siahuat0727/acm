#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Cake
{
	int r, h;
};

vector <Cake> V;
vector <Cake> IN;
double dp[1001];
bool cmp1(Cake a, Cake b){
	return a.r*a.h < b.r*b.h;
}

bool cmp2(Cake a, Cake b){
	return a.r < b.r;
}

bool cmp3(Cake a, Cake b){
	return a.r + 2*a.h < b.r + 2*b.h;
}
void findMin(vector<Cake> IN, int &j){
	int len = IN.size();
	long long Min = 1000000000000000000;
	for(int i = 0; i < len; ++i){
		if((long long)IN[i].r*IN[i].h < Min){
			Min = (long long)IN[i].r*IN[i].h;
			j = i;
		}
	}
}
void solve(){
	int k, n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i){
		dp[i] = 0;
		int r, h;
		scanf("%d%d", &r, &h);
		Cake cake = {r, h};
		V.push_back(cake);
	}
	sort(V.begin(), V.end(), cmp2);
	double now = 0;
	for(int i = 0; i < k; ++i){
		IN.push_back(V[i]);
		now += 2*M_PI*V[i].r*V[i].h;
	}
	now += M_PI*V[k-1].r*V[k-1].r;
	double lastR = V[k-1].r;
	for(int i = k; i < n; ++i){
		int j;
		findMin(IN, j);
		double tmp = now-M_PI*lastR*lastR + M_PI*V[i].r*V[i].r - 2*M_PI*IN[j].r*IN[j].h + 2*M_PI*V[i].r*V[i].h;		
		if(tmp > now){
			IN.erase(IN.begin()+j);
			IN.push_back(V[i]);
			lastR = V[i].r;
			now = tmp;
		}
	}




	printf("%.9lf\n", now);
}
	
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
    	V.clear();
    	IN.clear();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
