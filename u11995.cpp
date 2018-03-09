#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		stack<int> S;
		queue<int> Q;
		priority_queue<int> PQ;
		bool b_S = true, b_Q = true, b_PQ = true;
		while(n--){
			int oper, num;
			scanf("%d %d", &oper, &num);
			if(oper == 1){
				S.push(num);
				Q.push(num);
				PQ.push(num);
			}else{
				if(b_S){
					if(S.empty() || S.top() != num)
						b_S = false;
					else
						S.pop();
				}
				if(b_Q){
					if(Q.empty() || Q.front() != num)
						b_Q = false;
					else
						Q.pop();
				}
				if(b_PQ){
					if(PQ.empty() || PQ.top() != num)
						b_PQ = false;
					else
						PQ.pop();
				}
			}
		}
		int posible = b_S + b_Q + b_PQ;
		switch(posible){
			case   0:	printf("impossible\n");
						break;
			case   1:	printf("%s\n", b_S ? "stack" : b_Q ? "queue" : "priority queue");
						break;
			default :	printf("not sure\n");
						break;
		}

	}
	return 0;
}