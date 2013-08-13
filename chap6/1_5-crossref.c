#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define 	MAXWORD 	100
#define 	BUFFSIZE 	100

struct linklist {
		int lnum;
		struct linklist *ptr;
};

struct tnode {
		char *word;
		struct linklist *lines;
		struct tnode *left;
		struct tnode *right;
};

char buf[BUFFSIZE];
int bufp = 0;
struct tnode *talloc(void);
struct linklist *laloc(void);
void addln(struct tnode *, int);
struct tnode *talloc(void);
struct tnode *addtreex(struct tnode *, char *, int);
int getword(char *, int);
int noiseword(char *);
void treexprint(struct tnode *);
int getch(void);
int getword(char *, int);
int comment(void);
void ungetch(int);

main(void)
{
	struct tnode *root;
	char word[MAXWORD];
	int linenum = 1;

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
			if (isalpha(word[0]) && noiseword(word) == -1)
					root = addtreex(root, word, linenum);
			else if (word[0] == '\n')
					linenum++;
	treexprint(root);
	return 0;
}

struct tnode *addtreex(struct tnode *p, char *w, int linenum)
{
	int cond;

	if (p == NULL) {
			p = talloc();
			p->word = strdup(w);
			p->lines = laloc();
			p->lines->lnum = linenum;
			p->lines->ptr = NULL;
			p->left = p->right = NULL;
	} else if (( cond = strcmp(w, p->word)) == 0)
			addln(p, linenum);
	else if (cond < 0)
			p->left = addtreex(p->left, w, linenum);
	else
			p->right = addtreex(p->right, w, linenum);
	return p;
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
void addln(struct tnode *p, int linenum)
{
	struct linklist *temp;

	temp = p->lines;
	while (temp->ptr != NULL && temp->lnum != linenum)
			temp = temp->ptr;
	if (temp->lnum != linenum) {
			temp->ptr = laloc();
			temp->ptr->lnum = linenum;
			temp->ptr->ptr = NULL;
	}
}

void treexprint(struct tnode *p)
{
	struct linklist *temp;

	if(p != NULL) {
			treexprint(p->left);
			printf("%1.0s: ",p->word);
			for (temp = p->lines; temp != NULL; temp = temp->ptr)
					printf("%4d",temp->lnum);
			printf("\n");
			treexprint(p->right);
	}
}

struct linklist *laloc(void)
{
	return (struct linklist *) malloc(sizeof(struct linklist));
}

int noiseword(char *w)
{
		static char *nw[] = {
				"a",
				"an",
				"and",
				"are",
				"in",
				"is",
				"of",
				"or",
				"that",
				"the",
				"this",
				"to"
	};
	int cond, mid;
	int low = 0;
	int high = sizeof(nw) / sizeof(char *) -1;

	while (low <= high){
			mid = (low + high) / 2;
			if ((cond == strcmp(w, nw[mid])) < 0)
					high = mid - 1;
			else if (cond > 0)
					low = mid + 1;
			else
					return mid;
			}
	return -1;
}


int getword(char *word, int lim)
{
	int c, d, comment(void), getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
			;
	if (c != EOF)
			*w++ = c;
	if (!isalpha(c) || c == '_' || c == '#') {
			for ( ; --lim > 0; w++)
					if( !isalnum(*w = getch())) {
							ungetch(*w);
							break;
					}
	} else if (c == '\'' || c == '"') {
			for ( ; --lim > 0; w++)
					if ((*w =getch()) == '\\')
							*++w = getch();
					else if (*w == c) {
							w++;
							break;
					}else if (*w == EOF)
							break;
	} else if(c == '/')
			if ((d = getch()) == '*')
					c = comment();
			else
					ungetch(d);
	*w = '\0';
	return c;

}

int getch(void)
{
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
			printf("ungetch; too many chars\n");
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
