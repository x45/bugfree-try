#include <stdio.h>
#include <math.h>

int htoi(char s[]);
int strlen(char s[]);

int main()
{
	int dec;
	char hex[] = "0x164";
	dec = htoi(hex);
      	printf("%s in decimal is %d.\n", hex, dec);
	return 0;
}

