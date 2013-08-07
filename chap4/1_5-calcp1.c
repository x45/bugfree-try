#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
#define MAXOP           100
#define NUMBER          '0'
 
int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop (void);
 
int main(int argc, const char *argv[])
{
		int type;
		double op2;
		char s[MAXOP];
		while (( type = getop(s)) != EOF) {
				switch (type) {
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
						case '%':
								op2 = pop();
								if (op2 != 0.0)
										push((int) pop() % (int) op2 );
								else 
										printf("Error: zero divisor\n");
								break;
						case '/':
								op2 = pop();
								if (op2 != 0.0)
										push (pop() / op2);
								else
										printf("Error: zero divisor\n");
								break;
						case '\n':
								printf("\t%.8g\n",pop());
								break;
						default:
								printf("Error: unknown cmd %s\n",s);
								break;
				}
		}	
		return 0;
	}

#define MAXVAL 100
 
int sp = 0;
double val[MAXVAL];
 
void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("Stack full :  %g\n",f);
}
 
double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf("Stack empty\n");
                return 0.0;
        }
}
 
int getop(char s[])
{
        int i, c;
 
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                        ;
        s[1] = '\0';
        if (!isdigit(c) && c != '.'&& c != '-')
                return c;
        i = 0;
        if(c == '-') {
                if (isdigit(c = getch()) || c == '.')
                                s[++i] = c;
                else {
                                if (c != EOF)
                                                ungetch(c);
                                return '-';
                }
        }
        if (isdigit(c))
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF)
                ungetch(c);
        return NUMBER;
}
 
#define BUFFSIZE 100
 
char buf[BUFFSIZE];
int bufp = 0;
 
int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}
 
void ungetch(int c)
{
        if (bufp >= BUFFSIZE)
                printf("Too many chars \n");
        else
                buf[bufp++] = c;
}
