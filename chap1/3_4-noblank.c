#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main (int argc, char const* argv[])
{
	char line[MAXLINE];
	while (get_line(line,MAXLINE) > 0)
		printf("%s",line);
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) != EOF && c != ' '&& c!= '\t' && c != '\n'; ++i)
		s[i] = c;
	if (c == ' ' || c == '\t') {
		s[i] = '\0';
	}	
	else if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
