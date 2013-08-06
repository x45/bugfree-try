#include <stdio.h>
#define MAXLIN 1000

int get_line(char line[], int max);
int stringdex(char source[], char searchfor[]);

int main(int argc, const char *argv[])
{
		return 0;
}

int get_line(char s[], int lim)
{
		int c, i;

		i = 0;

		while(--lim > 0 && (c=getchar()) != EOF && c!= '\n')
				s[i++] = c;
		if (c == '\n') {
			s[i++] = c;
		s[i] = '\0';
		return i;	
		}
}
