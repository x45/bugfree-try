int readlines(char *lineptr[], int maxlines)
{
	int len,nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while (( len = get_line(line,MAXLEN)) > 0)
			if (nlines >= maxlines || (p = alloc(len)) == NULL)
					return -1;
			else {
					line[len-1] = '\0';
					strcpy(p, line);
					lineptr[nlines++] = p;
			}
	return nlines;
}



int readlines(char line[][MAXLINE], int maxlines)
{
	int len,nlines;

	nlines = 0;
	while ((len = get_line(line[nlines],MAXLEN)) > 0)
			if (nlines >=maxlines)
					return -1;
			else{
				line[nlines++][len-1] = '\0';
			}
}



#define MAXTOR 5000


int readlines(char *lineptr[], char *linestor, maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;
	while ((len = get_line(line[nlines],MAXLEN)) > 0)
			if (nlines >=maxlines || p+line > linestop)
					return -1;
			else {
				line[len-1] = '\0';
				strcpy(p, line);
				lineptr[nlines++] = p;
				p += len;
			}
	return nlines;
}

