#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void revers_line(char t[],int len);

int main (int argc, char const* argv[])
{
	int len;
	char line[MAXLINE];
	while ((len =get_line(line,MAXLINE)) > 0)
	{
		revers_line(line,len);
		printf("%s",line); 
	}
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) != EOF && c!= '\n';++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void revers_line(char t[], int len)
{
	int i, j = 0;
	char r[len+1];

	for (i = len-1; i >=0 ; --i)
	{
		r[j] = t[i];
		++j;
	}
	r[j] = '\0';

	for (i = 0; i < len+1 ; ++i)
	{
		t[i] = r[i];
	} 
}
