#include <ctype.h>

int atoi(char s[]);

int main(int argc, char const* argv[])
{

	return 0;
}

int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = ( s[i] == '-') ? -1 :1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign *n;
}
