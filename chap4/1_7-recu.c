#include <stdio.h>

void printfd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n /10)
			printd(n/10);
	putchar(n%10+'0');
}
