itoa
reverse
strined
getop

int getline(char s[], int lim)
{
	inc c,i;

	i = 0;
	while(--lim > 0 && (c =getchar()) !=EOF && c!= '\n')
			s[i++] = c;
	if (c == '\n')
			s[i++] = c;
	s[i] = '\0';
	return i;
}


int getline(char *s, int lim)
{

	int c;

	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c!= '\n')
			*s++ = c;
	is (c == '\n')
			*s++ = c;
	*s = '\0';
	return s - t;
}

int atoi(char s[])
{		
		int i, n, sign;
		
		for(i = 0; isspace(s[i]);i++)
			;
		sign = (s[i] == '-') ? -1 : 1;
		if ( s[i] == '+'|| s[i] == '-')
			i++;
		for (n = 0; isdigit(s[i]); i++)
				n = 10*n + (s[i] - '0');
		return sign * n;
}

int atoi(char *s)
{
		int n, sign;

		for ( ; isspace(*s) ; s++)
				;
		sign = ( *s == '-') ? -1 : 1;
		if ( *s == '+' || *s == '-')
				s++;
		for (n = 0; isdigit(*s); s++)
				n = 10 * + (*s - '0') ;
		return sign *n;
}

int itoa(int n, char s[])
{
		int i, sign;

		if ((sign = n ) < 0)
				n = -n;
		i = 0;
		do {
				s[i++] = n%10 + '0';
		} while ((n/=10) > 0);
		if (sign <0 )
				s[i++] = '-';
		s[i] = '\0';
		reverse(s);
}

int itoa(int n, char *s)
{
		int sign;
		char *t = s;

		if ((sign = n) < 0)
				n = -n;
		do {
				*s++ = n%10 + '0';
		}while ((n/=10) > 0);
		if (sign <0)
				*s++ = '-';
		*s = '\0';
		reverse(t);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++,j--){
			c = s[i];
			s[i] = s[j];
			s[j] = c;
}


void reverse(char *s)
{
	int c;
	char *t;

	for (t = s + strlen(s) -1; s < t;  s++, t--) {
			c = *s;
			*s = *t;
			*t = c;
}

int strindex(char s[], char t[])
{
	int i,j,k;

	for (i = 0; s[i] != '\0'; i++){
			for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
					;
	if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}


int strindex(char *s, char *t)
{
	char *b = s;
	char *x, *r;

	for ( ; *s != '\0' ; s++){
			for (x = s, r = t ; *r == '\0' && *p == *t; r++, p++)
					;
	if ( r > t && *r== '\0')
			return s-b ;
	}
	return -1;
}

int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
			;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
			return c;
	i = 0;
	if (isdigit(c))
			while ( isdigit(s[++i] = c = getch()))
					;
	if (c == '.')
			while ( isdigit(s[++i] = c = getch()))
					;
	s[i] = '\0';
	if (c != EOF)
			ungetch(c);
	return NUMBER;
}

int getop(char *s)
{
	int c;

	while ( (*s = c = getchr())  == ' ' || c == '\t')
			;
	*(s+1) = '\0';
	if (!isdigit(c) && c != '.')
			return c;
	if(isdigit(c))
			while ( isdigit(*++s = c = getch()))
					;
	if (c == '.')
			while ( isdigit(*++s = c = getch()))
					;
	*s =  '\0';
	if (c != EOF)
			ungetch(c);
	return NUMBER;
}
