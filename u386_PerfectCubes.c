#include <stdio.h>
#include <math.h>
#define CUBE(n) ((n)*(n)*(n))
//#define PRINT(n) (printf(#n" = %d\t", (n)))
int main(){
	for (int a = 2; a <= 200 ; ++a){
		const int Cube_a = CUBE(a);
		const int Max_b = (int)floor(cbrt(Cube_a/3));
		for (int b = 2; b <= Max_b; ++b){
			const int Cube_b = CUBE(b);
			const int Max_c = (int)floor(cbrt((Cube_a - Cube_b)/2));
			for (int c = b; c <= Max_c; ++c){
				const int Cube_c = CUBE(c);
				const int d = (int)round(cbrt(Cube_a - Cube_b - Cube_c));
				if(CUBE(d) == Cube_a - Cube_b - Cube_c)
					printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
			}
		}
	}
}