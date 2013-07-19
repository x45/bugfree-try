#include <stdio.h>
int main (int argc, char const* argv[])
{
	double nc;
	for (nc =0; getchar() != EOF;++nc);
	printf("%.0f",nc);
	return 0;
}

