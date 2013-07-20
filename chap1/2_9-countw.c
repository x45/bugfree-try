#include <stdio.h>

#define MAX 93

int main (int argc, char const* argv[])
{
	int c, i, count[MAX]= { 0 };
	

	while ((c = getchar()) != EOF){
		if (c >=30 && c <= 122)
			++count[(c-30)];
		else if (c == '\n')
			break;
	}

	printf("Case\t|\tOccurances\n");
	for (i = 0; i < MAX; ++i){
		printf("%c\t|\t%d\n",(i+30),count[i]);
	}


}
