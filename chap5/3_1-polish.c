#include <stdio.h>
#include <stdlib.h>
#define NUMBER '0'
#define MAX 100

void un_gets(char []);
int getop(char []);
void push(double);
double pop(void);


int main(int argc, const char *argv[])
{
	double op2;
	char s[MAX];

	while (--argc > 0) {
			un_gets(" ");
			un_gets(*++argv);
			switch(getop(s)) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("Error: unknown command %s\n",s);
				argc = 1;
				break;
			}
	}
	printf("\t%.8g\n",pop());
	return 0;
}

