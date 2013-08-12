#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 100
#define MAXWORD 100

char buf[BUFFSIZE];
int bufp = 0;
struct tnode {
		char *word;
		int count;
		struct tnode *left;
		struct tnode *right;
};

struct tnode *talloc(void);
char *str_dup(char *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int comment(void);
void ungetch(int);
int getch(void);

int main(int argc, const char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
			if (isalpha(word[0]))
					root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if (p == NULL) {
			p = talloc();
			p->word = str_dup(w);
			p->count = 1;
			p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
			p->count++;
	else if (cond < 0)
			p->left = addtree(p->left, w);
	else
			p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
			treeprint(p->left);
			printf("%4d, %s\n", p->count, p->word);
			treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *str_dup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
			strcpy(p, s);
	return p;
}

int getword(char *word, int lim)
{
	int c, d, comment(void), getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
			;
	if (!isalpha(c) || c == '_' || c == '#') {
			for ( ; --lim > 0; w++)
					if (!isalnum(*w = getch())){
							ungetch(*w);
							break;
					}
	} else if (c == '\'' || c == '"') {
			for ( ; --lim > 0; w++)
					if ((*w = getch()) == '\\')
							*++w = getch();
					else if (*w == c) {
							w++;
							break;
					} else if (*w == EOF)
							break;
	} else if (c == '/')
			if ((d = getch()) == '*')
					c = comment();
			else
					ungetch(d);
	*w = '\0';
	return c;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
			printf("ungetch: too many chars\n");
	else
			buf[bufp++] = c;
}

int comment(void)
{
	int c;
	while ((c = getch()) != EOF)
			if (c == '*')
					if ((c = getch()) == '/')
							break;
					else
							ungetch(c);
	return c;
}
