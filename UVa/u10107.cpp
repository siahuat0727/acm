#include <cstdio>
#include <algorithm>
using namespace std;
unsigned int n[10005];

int main(){
	int x;
	int count = 0;
	while(scanf("%d", &x) != EOF){
		n[count++] = x;
		sort(n, n+count);
		printf("%d\n", count & 0x1 ? n[count >> 1] : (n[(count-1) >> 1] + n[count >> 1]) >> 1);
	}
	return 0;
}