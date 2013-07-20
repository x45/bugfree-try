#include <stdio.h>

#define MAXSIZE 100

int main (int argc, char const* argv[])
{
	int c, i, j, count = 0, wn = 0, word[MAXSIZE];

	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\n' && c!= '\t')
			++count;
		else{
			word[wn] = count;
			count = 0;
			++wn;
		}
	}
	
	for (i = 0; i < wn; ++i){
		printf("%d",i+1);
		for (j=0;j < word[i];++j){
			printf("*");
		}
		printf("\n");
	}
}
