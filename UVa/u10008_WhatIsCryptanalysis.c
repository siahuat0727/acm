#include <stdio.h>
#include <stdlib.h>
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11
#define L 12
#define M 13
#define N 14
#define O 15
#define P 16
#define Q 17
#define R 18
#define S 19
#define T 20
#define U 21
#define V 22
#define W 23
#define X 24
#define Y 25
#define Z 26

int main(){
	int n;
	scanf("%d", &n);
	char ch;
	char arr[27] = {0};
	while(getchar()!='\n');
	for(int i = 0; i < n; ++i){
		while((ch = getchar())!= '\n'){
			switch(ch){
				case 'a': case 'A' : arr[A]++; break;
				case 'b': case 'B' : arr[B]++; break;
				case 'c': case 'C' : arr[C]++; break;
				case 'd': case 'D' : arr[D]++; break;
				case 'e': case 'E' : arr[E]++; break;
				case 'f': case 'F' : arr[F]++; break;
				case 'g': case 'G' : arr[G]++; break;
				case 'h': case 'H' : arr[H]++; break;
				case 'i': case 'I' : arr[I]++; break;
				case 'j': case 'J' : arr[J]++; break;
				case 'k': case 'K' : arr[K]++; break;
				case 'l': case 'L' : arr[L]++; break;
				case 'm': case 'M' : arr[M]++; break;
				case 'n': case 'N' : arr[N]++; break;
				case 'o': case 'O' : arr[O]++; break;
				case 'p': case 'P' : arr[P]++; break;
				case 'q': case 'Q' : arr[Q]++; break;
				case 'r': case 'R' : arr[R]++; break;
				case 's': case 'S' : arr[S]++; break;
				case 't': case 'T' : arr[T]++; break;
				case 'u': case 'U' : arr[U]++; break;
				case 'v': case 'V' : arr[V]++; break;
				case 'w': case 'W' : arr[W]++; break;
				case 'x': case 'X' : arr[X]++; break;
				case 'y': case 'Y' : arr[Y]++; break;
				case 'z': case 'Z' : arr[Z]++; break;
			}
		}
	}
	for(int i = A; i <= Z; ++i)
		printf("%d\n", arr[i]);
	return 0;

}
