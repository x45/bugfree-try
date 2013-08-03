#include <stdio.h>
#include <string.h>

#define SPACE ' '

void reverse(char s[]);
void itoa(int n, char s[], int min);


int main (int argc, char const* argv[])
{
	int num = 17;
	int min = 20;
	char str[20];
	
	printf("Int: %d\n", num);
	itoa(num, str, min);
	printf("Str: %s\n", str);
	return 0;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int min)
{
	int i, sign;
	long long int num = n;

	if ((sign = num) < 0)
		num = -num;
	i = 0;
	do {
		s[i++] = num % 10 + '0';
	} while (( num /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	while ( i < min )
		s[i++] = SPACE;
	s[i] = '\0';
	reverse(s);
}
