#include <stdio.h>
#include <ctype.h>

#define 	NUMBER '0'

int getop(char s[])
{
	int c, rc;
	float f;

	while ((rc = scanf("%c", &c)) != EOF)
			if ((c[0] = c) != ' ' && c != '\t')
					break;
	s[1] = '\0';
	if (rc == EOF)
			return EOF;
	else if (!isdigit(c) && c!= '.')
			return c;
	ungetc(c, stdin);
	scanf("%f", &f);
	sprintf(c, "%f", f);
	return NUMBER;
}
