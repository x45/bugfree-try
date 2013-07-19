#include <stdio.h>

#define IN  1
#define OUT 0

int main (int argc, char const* argv[])
{
	int st,c;
	st = OUT;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t'){
			st = IN;
			putchar (c);
			}
		else{
			if (st == IN){
				st = OUT;
				putchar ('\n');
			}
		}
	}
	if (st == IN)
		putchar ('\n');
}

