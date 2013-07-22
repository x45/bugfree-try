#include <stdio.h>
#define TABS 10

int main (int argc, char const* argv[])
{
	int c, tabc = TABS;
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			while(tabc-- > 0)
				putchar (' ');
			tabc = TABS;
		}
		else{
			if (c == '\n' || --tabc == 0)
				tabc = TABS;
			putchar (c);
		}
	}
	return 0;
}

