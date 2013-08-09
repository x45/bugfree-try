//array vers.


void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while((s[i] = t[i]) != '\0'){
			s++;
			t++;
	}
}

// point vers.


void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0'){
			s++;
			t++;
	}
}

// point vers2.


void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) !=  '\0')
			;
}

// point vers3.


void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
			;
}
