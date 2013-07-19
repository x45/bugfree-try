#include <stdio.h>
int main (int argc, char const* argv[])
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	celsius = lower;
	printf("    *F \t\t *C\n");
	while (celsius <= upper) {
		fahr = (((5.0/9.0) * celsius)+32.0);
		printf ("%6.1f %8.0f\n",celsius,fahr);
		celsius+= step;
	}
	return 0;
}

