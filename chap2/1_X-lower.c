#include <stdio.h>
#define MAXLEN 20
int lower (int c);

int main (int argc, char const* argv[])
{
	int c, i;;
	char s[MAXLEN];
	for (i=0; i<MAXLEN - 1 && (c=getchar()) != '\n' && c!=EOF;++i)
		s[i] = lower(c);
		s[i] = '\0';
	printf("%s\n",s);	
	return 0;
}


int lower (int c)
{
	return (c >= 'A' && c <= 'Z') ? c+ 'a' - 'A' : c;
}

