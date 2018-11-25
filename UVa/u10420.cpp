#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(){
	char str[76];
	int n;
	scanf("%d", &n);
	fgets(str, 76, stdin);
	map<string, int> M;
	map<string, int>::iterator it;
	while(n--){
		fgets(str, 76, stdin);
		char country[76];
		sscanf(str, "%s", country);
		it = M.find(country);
		if(it != M.end())
			it->second++;
		else
			M[country] = 1;
	}
	for(it = M.begin(); it != M.end(); it++)
		printf("%s %d\n", it->first.c_str(), it->second);
	return 0;
}