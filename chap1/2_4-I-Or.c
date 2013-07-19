#include <stdio.h>
int main (int argc, char const* argv[])
{
	int c, sw;
	while ((c = getchar()) != EOF){
		sw = 0;
		if (c == '\t'){
			putchar ('\\');
 			putchar ('t');
			sw = 1;
		}
		if (c == '\b'){
			putchar ('\\');
			putchar ('b');
			sw = 1;
		}
		if (c == '\\'){
			putchar ('\\');
			putchar ('\\');
			sw = 1;
		}
		if (sw == 0){
			putchar (c);
		}	
	}
	return 0;
}
