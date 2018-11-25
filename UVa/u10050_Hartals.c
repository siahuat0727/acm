z#include <stdio.h>
#include <stdbool.h>

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		bool lose[N + 1];
		for (int i = 0; i < N + 1; ++i)
			lose[i] = false;
		int P;
		scanf("%d", &P);
		int h[P];
		for (int i = 0; i < P; ++i)
			scanf("%d", &h[i]);
		for (int i = 1; i < N + 1; ++i)
			for (int j = 0; j < P; ++j)
				if(i % h[j] == 0 && i % 7 != 0 && i % 7 != 6)
					lose[i] = true;
		int hartal = 0;
		for (int i = 1; i < N + 1; ++i)
			if(lose[i] == true)
				hartal++;
		printf("%d\n", hartal);
	}
}