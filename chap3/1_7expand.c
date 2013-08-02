#include <stdio.h>
#define MAX 100
void expand(char s1[], char s2[]);

int main (int argc, char const* argv[])
{
	char b[MAX] = { 0 } ;
	char a[MAX] = "e-j 1-5 s-v";
	expand(a,b);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, a;
	for (i = j = 0; (a = s1[i]) != '\0'; i++){
		if (s1[i+1] == '-' && s1[i] < s1[i+2]){
			while (a < s1[i+2])
				s2[j++] = a++;
			i++;
		}
		else
			s2[j++] = a;
	}	
	s2[j] = '\0';
	printf("%s\n",s2);
}
