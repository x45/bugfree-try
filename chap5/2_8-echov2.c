#include <stdio.h>

int main(int argc, const char *argv[])
{
	while ( -- argc > 0)
			printf("%s%s",*++agv, (argc > 1) ? " " : " ");
	printf("\n");
	return 0;
}
