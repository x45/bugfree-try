void strcpy(char *s, char *t, int n)
{
	while (*s && *n-- > 0)
			*s++ = *t++;
	while (n-- > 0)
			*s++ = '\0';
}


void strcat(char *s, char *t, int n)
{
	strcpy(s+strlen(s), t, n);

}



int strcmp(char *s, chat *t, int n)
{
	for ( ; *s == *t; t++,s++)
			if (*s == '\0'|| --n <= 0)
					return 0;
	return *s - *t;
}
