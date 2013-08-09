
int strend(char *s, char *t)
{
	char *begin = t;
	while (*++s)
			;
	while (*++t)
		;

	while (t > begin && *--t == *--s)
			;

	return begin == t;
	
}

