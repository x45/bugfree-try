#include <stdio.h>
int main (int argc, char const* argv[])
{
	int c,nl,ta,bl;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
		else if (c == ' ')
			++bl;
		else if (c == '\t')
			++ta;	
	printf (" Tab: %d\n Blank: %d\n Line: %d\n",ta,bl,nl);
	return 0;
}

