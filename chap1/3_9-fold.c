#include <stdio.h>
#define MAXCHAR 10
#define MAXLINE 1000

char line[MAXLINE];

int get_line(void);

int main (int argc, char const* argv[])
{
	int t, len,lock,spacelock; 
	
	while ((len =get_line()) > 0){
		if (len < MAXCHAR)
		{}
		else {
			t = 0;
			lock = 0;
			while (t < len){
				if ( line[t] == ' ')
					spacelock = t;

				if ( lock == MAXCHAR){
					line[spacelock] = '\n';
					lock = 0;
				}	
				lock++;
				t++;
			}

		}
	printf("%s",line);
	}
	return 0;
}

int get_line(void)
{
	int c, i;
	extern char line[];
	for (i=0; i < MAXLINE && (c = getchar ()) != EOF && c!= '\n';++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

