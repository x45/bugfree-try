// array vers.

int strcmp(char *s, char*t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
			if (s[i] == '\0')
					return 0;
	return s[i]-t[i];
}


// point vers.


int strcmp(char *s, char *t)
{

	for ( ; *s == *t ; t++, s ++)
			if ( *s == '\0')
					return 0;
	return *s - *t;
}
