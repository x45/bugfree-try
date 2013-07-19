#include <stdio.h>
int main (int argc, char const* argv[])
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0; /* lower limite of temperature scale*/
	upper = 300; /* upper limit */
	step = 20; /* step size */
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

