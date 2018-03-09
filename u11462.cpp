#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
		vector<int> vec;
		while(n--){
			int age;
			scanf("%d", &age);
			vec.push_back(age);
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); ++i){
			if(i > 0)
				printf(" ");
			printf("%d", vec[i]);
		}
		printf("\n");
	}
	return 0;
}