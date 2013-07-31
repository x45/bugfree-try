#include <stdio.h>

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

int main (int argc, char const* argv[])
{
	char sent[] ="There are tabs\t\tembedded in this sentence.  \\As well as newlines\n\nand one \b backspace.";
	char new[1000];
	printf("Original : \n%s\n",sent);
	escape(new,sent);
	printf("Escape: \n%s\n",new);
	unescape(sent,new);
	printf("Unescape: \n%s\n",sent);
	return 0;
}

int escape(char s[], char t[])
{
	int i = 0;
	int j = 0;

	while (t[i] != '\0'){
		switch (t[i]){
			case '\n':
				s[j++] = '\\';
				s[j]   = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j]   = 't';
				break;
			case '\b':
				s[j++] = '\\';
				s[j]   = 'b';
				break;
			default:
				s[j]  = t[i];
				break;
		}
		++i;
		++j;
	}
	s[j] = '\0';	

}

int unescape(char s[], char t[])
{
	int i = 0;
	int j = 0;

	while(t[i] != '\0'){
		switch(t[i]){
			case'\\':
				i++;
				if(t[i] == 'b')
					s[j] = '\b';
				else if(t[i] == 'n')
					s[j] = '\n';
				else if(t[i] == 't')
					s[j] = '\t';
				else{
					s[i] = '\\';
					--i;
				}
				break;
			default:
				s[j] = t[i];	
				break;
		}
		++i;
		++j;
	}
	s[j] = '\0';	
}
