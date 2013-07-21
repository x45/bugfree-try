#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main (int argc, char const* argv[])
{
	int len, max = 0;
	char line[MAXLINE], longest[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("This is the longest line with %d char.\n",max);  // add for 1.16
		printf("%s", longest);
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c!= '\n' ; ++i)
		s[i] =c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i=0;

	while ((to[i] = from[i]) != '\0')
		++i;
}
