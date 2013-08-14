#include <stdio.h>

int main(int argc, const char *argv[])
{
	char *c = "hello, world";
	printf("%s\n",c);
	printf("%10s\n",c);
	printf("%.10s\n",c);
	printf("%-10s\n",c);
	printf("%.15s\n",c);
	printf("%15.10s\n",c);
	printf("%-15.10s\n",c);
	return 0;
}
