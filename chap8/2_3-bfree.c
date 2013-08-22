#include <sys/syscall.h>

unsigned bfree(char *p, unsigned n)
{
	Head *hp;

	if (n < sizeof(Header))
			return 0;
	hp = (Header *)p;
	hp->s.size = n / sizeof(Header);
	free((void *)(hp+1));
	return hp->s.size;
}
