#include <cstdio>
#include <stack>
using namespace std;

int main(){
	// freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		stack<char> S;
		char line[130];
		fgets(line, 130, stdin);
		bool equi = true;
		for (int i = 0; line[i] != '\0'; ++i){
			char c = line[i];
			switch(c){
				case '(': 
				case '[': 	S.push(c);
							break;
				case ')': 	if(S.empty()){
								equi = false;
								break;
							}
							if(S.top() == '(')
								S.pop();
							else
								equi = false;
							break;
				case ']': 	if(S.empty()){
								equi = false;
								break;
							}
							if(S.top() == '[')
								S.pop();
							else
								equi = false;
							break;
			}
			if(!equi)
				break;
		}
		if(!S.empty())
			equi = false;
		printf("%s\n", equi ? "Yes" : "No");
	}
	return 0;
}