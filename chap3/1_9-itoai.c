#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);


int main (int argc, char const* argv[])
{
	int num = INT_MIN;
	char str[10];
	printf("Int : %d \n", num);
	itoa(num,str);
	printf("Str : %s \n", str);
	return 0;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void itoa(int n, char s[])
{
	int i, sign;
	long long int num = n;

	if (( sign = num) < 0)
		num = -num;

	i = 0;

	do {
		s[i++] = num % 10 + '0';
	}while ((num /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
