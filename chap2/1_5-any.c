#include <stdio.h>

int any(char s1[],char s2[]);

int main (int argc, char const* argv[])
{
	int inde;	
	inde = any("tommy","jerry");
	printf("%d\n",inde);
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[j] == s2[i])
				return i;
	return -1;
		
	
}

