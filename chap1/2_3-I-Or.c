#include <stdio.h>
int main (int argc, char const* argv[])
{
	int c, bl;
	bl = 1;
	while ((c = getchar()) != EOF){
		if (c != ' '){
			if (bl == ' ')
				putchar (bl);
			putchar (c);
		}
		bl = c;	
	}
	if (bl == ' '){
		putchar (bl);
	}
	return 0;
}

