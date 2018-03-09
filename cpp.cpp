#include <stdio.h>

#include <cmath>
double getArea(double a, double b, double c){
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
	// printf("%.4lf\n", getArea(85.608, 51.381, 35.568));
	printf("%d\n", EOF);
    return 0;
}
