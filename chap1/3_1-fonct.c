#include <stdio.h>

float fahr(float m);

int main (int argc, char const* argv[])
{
	float lower, upper, step;
	float fahrr,x;
	lower = 0;
	upper = 300;
	step = 20;
	printf("Cel\t|\tFahr\n");
	fahrr = lower;
	while (fahrr <= upper) {
		x = fahr(fahrr);
		printf("%.0f\t|\t%.1f\n",fahrr,x);
		fahrr+=step;
	}
	return 0;
}

float fahr(float m)
{
	float p;
	p = (5.0/9.0) * (m-32.0);
	return p;
}
