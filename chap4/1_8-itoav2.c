void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
			n = -n;
	i = 0;
	do {
		s[i++] = n%10+'0';
	} while ((n/=10) > 0);
	if (sign < 0)
			s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa(int n, char *s)
{
	static pos = 0;
	if (n < 0){
			s[pos++]='-';
			n =-n;
	}
	i = 0;
	if (n /10)
			itoa(a/10,s);
	s[pos++] = a % 10+'0';
	s[pos] = '\0';
}
