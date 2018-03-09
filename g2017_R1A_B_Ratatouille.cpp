#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct range{
	int Min;
	int Max;
};

int R[51];
int Q[51][51];
double eps = 1e-8;

bool cmp(range a, range b){
	if(a.Max == b.Max)
		return a.Min < b.Min;
	return a.Max < b.Max;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case){
		int n, p;
		scanf("%d %d", &n, &p);
		for (int i = 0; i < n; ++i)
			scanf("%d", &R[i]);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < p; ++j)
				scanf("%d", &Q[i][j]);
		vector<range> V[n];
		for (int i = 0; i < p; ++i){
			// int Max = 10000000;
			// int Min = -1;
			int last;
			for (int j = 0; j < n; ++j){
				double tmax = (double)Q[j][i]*10/9/R[j] + eps;
				double tmin = (double)Q[j][i]*10/11/R[j] - eps;
				if((int)tmax <= (int)tmin){
					continue;
				}
				// printf("V[%d] is push\n", j);
				range R = {(int)(tmin+1-eps), (int)tmax};
				V[j].push_back(R);

			}
		}
		for (int i = 0; i < n; ++i)
			sort(V[i].begin(), V[i].end(), cmp);

		
		int num = 0;
		bool again = true;
		for (int i = 0; i < n; ++i){
			if(V[i].empty())
				again = false;
		}
		while(again){
			// printf("num = %d\n", num);
			// for (int i = 0; i < n; ++i)
			// {
			// 	printf("i=%d\n", i);
			// 	for (auto it = V[i].begin(); it != V[i].end() ; ++it)
			// 	{
			// 		printf("%d %d\n", it->Min, it->Max);
			// 	}
			// }
			int minMax = V[0][0].Min;
			int maxMin = V[0][0].Max;
			int maxMinI = 0;
			for (int i = 1; i < n; ++i){
				if(V[i][0].Min > minMax){
					minMax = V[i][0].Min;
				}
				if(V[i][0].Max < maxMin){
					maxMin = V[i][0].Max;
					maxMinI = i;
				}
			}
			if(minMax <= maxMin){
				for (int i = 0; i < n; ++i){
					V[i].erase(V[i].begin());
				}
				num++;
			}else{
				V[maxMinI].erase(V[maxMinI].begin());
			}

			for (int i = 0; i < n; ++i){
				if(V[i].empty())
					again = false;
			}	
		}
		printf("Case #%d: %d\n", Case, num);
	}

	return 0;
}