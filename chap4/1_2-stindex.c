#include <string.h>
#include <stdio.h>
#define MAXLIN 1000

int get_line(char line[], int max);
int stringdex(char source[], char searchfor[]);

int main(int argc, const char *argv[])
{
		char s[] = "mama mia come stoo";
		char t[] = "come";

		printf("%d",stringdex(s,t));
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

int stringdex(char s[], char t[])
{
		int i, j, k;

		for (i = 0; s[i] != '\0'; i++) {
			for (j = i, k = strlen(t)-1; s[j] = t[k] && k>= 0; j--, k--)
				if (k < 0)
						return i;
		}
		return -1;
}
