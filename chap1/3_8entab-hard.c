#include <stdio.h>
#define TABS 8

int main (int argc, char const* argv[])
{
	int c, tabc = TABS,pos = 0,ne = 0, nt = 0;
	while ((c = getchar()) != EOF){
		++pos;
		if (c == ' '){
			if (pos % TABS != 0)
				++ne;
			else
				ne = 0;
				++nt;
		}
		else{
			for(; nt > 0; --nt)
				putchar ('_');
			if (c == '\t')
				ne = 0;
			else
				for(; ne > 0; --ne)
					putchar ('.');
			putchar (c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABS - (pos -1) % TABS )-1;
		}
	}	
	return 0;
}
