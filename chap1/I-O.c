#include <stdio.h>
int main (int argc, char const* argv[])
{
	int c;
	while (c != EOF){
		putchar (c);
		c = getchar();	
	}
	return 0;
}

