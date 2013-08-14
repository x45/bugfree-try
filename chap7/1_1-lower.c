#include <stdio.h>
#include <ctype.h>

main(void)
{
	int c;

	while ((c = getchar()) != EOF)
			putchar(tolower(c));
	return 0;
}
