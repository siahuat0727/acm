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
#define eps 1e-8
vector<double> V;
void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	double u;
	scanf("%lf", &u);
	for (int i = 0; i < n; ++i){
		double t;
		scanf("%lf", &t);
		V.push_back(t);
	}
	sort(V.begin(), V.end());
	int i = 0;
	double tmp;
	double total = 0;
	bool flag = false;
	bool perfect = false;
	while(1){
		if(i==n-1){
			perfect = true;
			break;
		}
		tmp = V[i+1] - V[i];
		total += tmp*(i+1);
		if(abs(total-u) < eps){
			flag = true;
			break;
		}
		else if(total > u){
			total -= tmp*(i+1);
			break;
		}
		++i;
	}
	double Max;
	if(perfect){
		Max = V[n-1] + (u-total+eps)/n;
		// printf("%lf %lf\n",total , Max);
	}
	else if(flag){
		Max = V[i+1];
	}else{
		Max = V[i] + (u-total+eps)/(i+1);
	}
	double ans = 1;
	for(int j = 0; j <= i; ++j){
		ans *= Max;
	}
	for(int j = i+1; j < n; ++j){
		ans*= V[j];
	}
	if(ans > 1)
		ans = 1;
	printf("%.6lf\n", ans);

}
	
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
    	V.clear();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
