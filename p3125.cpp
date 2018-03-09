#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		queue<int> Q;
		priority_queue<int> PQ;
		int jobs, place;
		scanf("%d %d", &jobs, &place);
		while(jobs--){
			int m;
			scanf("%d", &m);
			Q.push(m);
			PQ.push(m);
		}
		int time = 0;
		bool finish = false;
		while(!finish){
			if(Q.front() == PQ.top()){
				Q.pop();
				PQ.pop();
				time++;
				if(place == 0)
					finish = true;
				else
					place--;
			}else{
				Q.push(Q.front());
				Q.pop();
				if(place == 0)
					place = Q.size() - 1;
				else
					place--;
			}
			// int size = Q.size();
			// for (int i = 0; i < size; ++i){
			// 	printf("%d ", Q.front());
			// 	Q.push(Q.front());
			// 	Q.pop();
			// }
			// printf(place = "%d\n", place);
		}
		printf("%d\n", time);
	}
	return 0;
}