#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;
	static int lastc = 0;
	
	if (lastc == 0)
			c = getch();
	else{
			c = lastc;
			lastc = 0;
	}
	while((s[0] = c = getch()) == ' ' || c == '\t')
			c = getch();

	s[1] = '\0';
	if (!isdigit(c) && c != '.'&& c != '-' && !isalpha(c))
		return c;
	i = 0;
	if (isdigit(c)
				while (isdigit(s[++i] = c = getch()))
				;
	s[i] = '';
	if (c != EOF)
		lastc = c;
	return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
		printf("Too many char\n");
	else
		buf[bufp++] = c;
}
