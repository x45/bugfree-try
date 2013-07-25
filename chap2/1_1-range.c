#include <stdio.h>
#include <limits.h>

int main (void)
{
	printf("Type          : \t MIN\t\t\tMAX\n");
	printf("Signed Char   : \t %d\t\t\t%d\n",SCHAR_MIN,SCHAR_MAX);
	printf("Unsigned Char : \t %d\t\t\t%d\n",0,UCHAR_MAX);
	printf("Char          : \t %d\t\t\t%d\n",CHAR_MIN,CHAR_MAX);
	printf("Short Int     : \t %d\t\t\t%d\n",SHRT_MIN,SHRT_MAX);
	printf("Unsigned Short: \t %d\t\t\t%d\n",0,USHRT_MAX);
	printf("Int           : \t %d\t\t%d\n",INT_MIN,INT_MAX);
	printf("Unsigned Int  : \t %d\t\t\t%u\n",0,UINT_MAX);
	printf("Long Int      : \t %ld\t%ld\n",LONG_MIN,LONG_MAX);
	printf("Unsigned Long : \t %d\t\t\t%u\n",0,ULONG_MAX);

	return 0;
}
