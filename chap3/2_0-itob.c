#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main (int argc, char const* argv[])
{
	int num;
	int base = 16;
	char str[100];

	if (argc > 1)
		num = atoi(argv[1]);
	else
		printf("No arguments.\n");

	if (argc > 2)
		base = atoi(argv[2]);
	str[0] = '\0';
	printf("%d in base 10 is:",num);
	itob(num,str,base);
	printf(" %s in base %d\n",str,base);
	return 0;
}


void reverse(char s[])
{
	int c, i, j;

	for (i =0, j = strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itob(int n, char s[], int b)
{
	int i, sign, rem;
	int converting = 1;

	long long int num = n;

	i = 0;

	if ((sign = num) < 0)
		num = -num;
	
	while (converting){
		rem = num % b;
		num = num / b;
		if (rem < 10){
			s[i++] = rem % 10 + '0';
			s[i] = '\0';
		}
		else if (rem > 10){
			s[i++] = rem % 10 + 'A';
			s[i] = '\0';
		}
		if (num == 0)
			converting = 0;
	}
	if ( sign < 0 ){
		s[i++] = '-';
		s[i] = '\0';
	}	
	reverse(s);
	s[i] = '\0';
}
