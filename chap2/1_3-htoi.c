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

int htoi(char s[])
{
	int sum, len, i, start, p;
	sum = 0;
	p = 0;

	for (i = 0; s[i] != '\0';++i){}
	len = i;	// len = size of s[]

	if (s[0] == '0' && s[1] == 'x' || s[1] == 'X')
	{
		start = 2;
	}
	else 				// test value if char used is hex.
	{
		start = 0;
	}

	for (i = len -1;i >= start;--i){
		if (s[i] == 'a' || s[i] == 'A')
			sum += 10 * pow(16,p);
		else if (s[i] == 'b' || s[i] == 'B')
			sum += 11 * pow(16,p);	
		else if (s[i] == 'c' || s[i] == 'C')
			sum += 12 * pow(16,p);	
		else if (s[i] == 'd' || s[i] == 'D')
			sum += 13 * pow(16,p);	
		else if (s[i] == 'e' || s[i] == 'E')
			sum += 14 * pow(16,p);	
		else if (s[i] == 'f' || s[i] == 'F')
			sum += 15 * pow(16,p);	
		else if (s[i] >= 0 && s[i] <= 9)
			sum += (s[i] -0) * pow(16,p);	
		else  
			printf("Invalid char in String");
	++p;}
}

