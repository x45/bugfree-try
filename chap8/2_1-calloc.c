#include <sys/syscall.h>

void *calloc(unsigned n, unsigned size)
{
	unsigned i, nb;
	char *p, *q;

	np = n * size;
	if ((p = q = malloc(nb)) != NULL)
			for (i = 0; i < nb; i++)
					*p++ = 0;
	return q;
}
