#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define EPS 1e-3
vector<double> V;

double getArea(double a, double b, double c){
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool greaterThan(double a, double b, double c){
	return a + b > c;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		V.clear();
		while(n--){
			double t;
			scanf("%lf", &t);
			V.push_back(t);
		}
		sort(V.begin(), V.end());
		double A = 0;
		while(1){
			// printf("qq 3%d %d\n", V.size(), V[V.size()-1]);
			if(V.size()<=2){
				break;
			}else if(greaterThan(V[V.size()-3], V[V.size()-2], V[V.size()-1])){
				// for(int i = V.size() - 2; i >= 1 && greaterThan(V[i-1], V[i], V[V.size()-1]); --i){
				// 	for(int j = V.size() - 3; j >= 0 && greaterThan(V[i], V[j], V[V.size()-1]); --j){
				// 		if(getArea(V[i], V[j], V[V.size()-1]) > A)
				if(getArea(V[V.size()-3], V[V.size()-2], V[V.size()-1]) > A)
					A = getArea(V[V.size()-3], V[V.size()-2], V[V.size()-1]);
				V.erase(V.end()-1);
				// 	}
				// }
			}else{
				V.erase(V.end()-1);
			}
		}
		printf("%.2lf\n", A);
	}
}