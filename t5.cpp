#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int edge[10];
int nE;
double binTry(double a, double b){
	cout << "In binTry" << endl;
	double ans = (a+b)/2;
	double total = 0;
	for (int i = 0; i < nE; ++i)
	{
		// printf("%d / (2*%f) = ", edge[i], ans);
		// cout << (double)asin(edge[i] / (2*ans)) << " ";
		double tmp = edge[i] / (2*ans);
		if(tmp >= 1)
			return binTry(ans, b);
		total += (double)asin(tmp);
		// cout << total << " ";
	}
	printf("qq total = %.10f a = %.10f b = %.10f\n", total, a, b);
	if(b-a < abs(1e-5))
		return ans;
	else if(total > M_PI/2)
		return binTry(ans, b);
	else
		return binTry(a, ans);
}

double calArea(double r, int l){
	double s = (2*r+l) / 3;
	return (s-r)*sqrt(s*abs(s-l));
}

int main(){
	int T;
	cin >> T;
	while(T--){
		double peri;
		cin >> peri;
		double r = peri / 2 / M_PI;
		cin >> nE;
		memset(edge, 0, sizeof edge);

		for (int i = 0; i < nE; ++i)
			cin >> edge[i];

		cout << 'a' << " r = " << r << endl;
		double small_r = binTry(0, r);
		cout << 'b' << endl;


		double small_A = 0;
		for (int i = 0; i < nE; ++i)
		{
			small_A += calArea(small_r, edge[i]);
		}
		cout << small_A << endl;
		cout << M_PI*r*r - small_A << endl;
	}
	return 0;
}
