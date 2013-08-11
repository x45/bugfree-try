#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define 	MAXSTR 		100
#define  	DIRE 		8
#define 	FOLD 		4
#define 	NUMERIC 	1
#define  	DECR 		2
#define  	LINES 		100
#define 	MAXLEN 		1000

int get_line(char *lineptr[], int maxlines);
int charcmp(char *, char *);
void substr(char *s, char *t, int maxstr);
void error(char *);
int numcmp(char *, char *);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int maxlines);
void qsort( char *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

char *alloc(int);
char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, const char *argv[])
{
	char *lineptr[LINES];
	int nlines;
	int rc = 0;
	readargs(argc, argv);
	if ((nlines = realines(lineptr, LINES)) > 0) {
			if (option & NUMERIC)
					qsort((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) numpcmp);
			else
					qsort((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) strcmp);
			writelines(lineptr, nlines, option & DECR);
			}else {
					printf("Too big to sort \n");
					rc = -1;
			}
	return rc;
}

void writelines(char *lineptr[], int nlines, int order)
{
	int i;

	if (order)
			for(i = nlines-1; i>=0; i--)
					printf("%s\n",lineptr[i]);
	else
			for(i = 0; i < nlines; i++)
					printf("%s\n",lineptr[i]);
}

int charcmp(char *s, char *t)
{
	char a, b;
	int i, j, endpos;
	extern char ption;
	extern int pos1, pos2;
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & DIRE) ? 1 : 0;

	i = j = pos1;
	if(pos2 > 0)
			endpos = pos2;
	else if ((endpos = strlen(s)) < strlen(t))
			endpos = strlen(t);
	do {
			if (dir) {
					while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] == '\0')
							i++;
					while (j < endpos && !!isalnum(*t) && t[j] != ' ' && t[j] != '\0')
						   j++;
			}
			if (i < endpos && j < endpos) {
					a = fold ? tolower(s[i]) : s[i];
					i++;
					b = fold ? tolower(t[j]) : t[j];
					j++;
					if (a == b && a == '\0')
						return 0;
			}
	}while (a == b && i < endpos && j < endpos);
	return a - b;
}

void readargs(int argc, char *argv[])
{
	int c;
	int atoi(char *);

	while (--argc > 0 && (c =(*++argv)[0]) == '-'|| c == '+'){
		if (c == '-' && !isdigit(*(argv[0]+)))
				while (c = *++argv[0])
					switch(c) {
					case 'd' :
						option |= DIRE;
						break;
					case 'f' :
						option |= FOLD;
						break;
					case 'n' :
						option |= NUMERIC;
						break;
					case 'r' :
						option |= DECR;
						break;
					default:
						printf("Unkown option %s\n",c);
						error("usage: sort -dfnr [+pos1] [-pos2]");
						break;
					}
		else if (c == '-')
				pos2 = atoi(argv[0]+1);
		else if ((pos1 = atoi(argv[0]+1)) < 0)
				error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
	if (argc || pos1 > pos2)
		error("Usage: sort -dfnr [+pos1] [-pos2]");
}

int numpcmp(char *s1, char *s2)
{
	double v1, v2;
	char str[MAXSTR];

	substr(s1, str, MAXSTR);
	v1 = atof(str);
	substr(s2, str, MAXSTR);
	v2 = atof(str);
	if (v1 < v2)
			return -1;
	else if (v1 > v2)
			return 1;
	else
			return 0;
}

void substr(char *s, char *str)
{
	int i, j, len;
	extern int pos1, pos2;

	len = strlen(s);
	if (pos2 > 0 && len > pos2)
			len = pos2;
	else if (pos2 > 0 && len < pos2)
			error("substr: Too short");
	for(j = 0, i = pos1; i < len; i++, j++)
			str[j] = s[i];
	str[j] = '\0';
}

void error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

void writelines(char *lineptr[], int nlines, int decr)
{
	int i;

	if (decr)
			for (i = nlines-1; i >=0; i--)
					printf("%s\n",lineptr[i]);
	else
			for (i = 0; i < nlines; i++)
					printf("%s\n",lineptr[i]);
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
			return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v , last+1, right,comp);
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if ( nlines >= maxlines || (p = alloc(len)) == NULL)
				return -1;
		else {
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

int get_line(char *s, int lim)
{
	int c;
	char *t = s;
	
	while (-- lim > 0 && (c = getchar()) != EOF && c!= '\n')
			*s++ = c;
	if (c == '\n')
			*s++ = c;
	*s = '\0';
	return s-t;
}
