#include <cstdio>
#include <algorithm>
using namespace std;
struct jobs{
	double ratio;
	int num;
};

jobs j[1005];

bool descending(jobs a, jobs b){
	return a.ratio > b.ratio;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		if(i)
			printf("\n");
		int m;
		scanf("%d", &m);
		int count = 0;
		while(m--){ // use for is better
			int t, f;
			scanf("%d %d", &t, &f);
			j[count].ratio = (double)f/t;
			j[count].num = count + 1;
			// printf("%d %lf\n", j[count].num, j[count].ratio);
			++count;
		}
		sort(j, j+count, descending);
		for (int i = 0; i < count; ++i){
			if(i)
				printf(" ");
			printf("%d", j[i].num);
		}
		printf("\n");
	}
	return 0;
}