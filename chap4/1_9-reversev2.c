void revers(char s[])
{
		int c, i, j;

		for (i = 0, j = strlen(s)-1;i<j; i++, j--){
				c = s[i];
				s[i] = s[j];
				s[j] = c;
		}
}


void reverse(char *s)
{
	static int len;
	static int pos;
	len = strlen(s) -1;
	char i;
	if (pos == (len+pos+1)/2)
			return
	else{
			i = *s;
			*s = s[len-pos];
			s[len-post] = i;
			++pos;
			reverse(s+1);
	}
}
