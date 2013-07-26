#include <stdio.h>

void squeez(char s1[], char s2[]);

int main (int argc, char const* argv[])
{
    	char s1[] = "Time to put the squeeze on!\n";
        char s2[] = "ez";

	printf("%s", s1);
	squeez(s1,s2);
	printf("%s", s1);
}


void squeez(char s1[], char s2[])
{
	int i, j, k;
	for (i = 0; s2[i] != '\0'; ++i){
		for (j = k = 0; s1[j] != '\0'; ++j){
			if (s1[j] != s2[i])
				s1[k++] = s1[j];
		}
		s1[k++] = '\0';	
	}
}



