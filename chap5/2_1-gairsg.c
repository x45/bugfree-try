getline
atoi
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


