#include <stdio.h>
int main (int argc, char const* argv[])
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0; 
	upper = 300; 
	step = 20; 
	printf("Here is a program who translate fahr into celsius.\n\n");
	printf(" *C\t*F\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf ("%3.0f %6.1f\n",fahr, celsius);
		fahr += step;
	}
	return 0;
}

