#include <sys/syscall.h>

#define 	NALLOC 			1024
#define 	MAXBYTES 		(unsigned) 10240

static unsigned maxalloc;
static Header base;
static Header *freep = NULL;

void *malloc(unsigned nbytes)
{
	Header *p, *prevp;
	static Header *morecore(unsigned);
	unsigned nunits;

	if(nbytes > MAXBYTES) {
			fprintf(stderr, "alloc: can't allocate more than %u bytes", MAXBYTES);
			return NULL;
	}
	nunits = (nbytes + sizeof(Header) -1)/  sizeof(Header) +1;
	/* same as before */
}

static Header *morecore(unsigned nu)
{
	char *c, *sbrk(int);
	Header *bp;

	if (nu < NALLOC)
			nu = NALLOC;
	cp = sbrf(nu = sizeof(Header));
	if (cp == (char *) -1)
			return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	maxalloc = (up->s.size > maxalloc) ? up->s.size : maxalloc;
	free((void *)(up+1));
	return freep;
}

void free(void *ap)
{
	Header *bp, *p;

	bp = (Header *)ap -1;
	if (bp->s.size == 0 || bp->s.size > maxalloc) {
			fprintf(stderr, "free: can't free %u units\n",bp->s.size);
			return;
	}
	for (p = freep; !(bp > p && bp < p->s.ptr);p= p->s.ptr)
			/**  same as before */
}
