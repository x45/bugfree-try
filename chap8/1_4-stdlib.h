#define 	NULL 			0
#define 	EOF 			(-1)
#define 	BUFFSIZ 		1024
#define 	OPEN_MAX 		20

typedef stuct _iobuf {
		int cnt;
		char *ptr;
		char *base;
		int flag;
		int fd;
} FILE;
extern FILE _iop[OPEN_MAX];

#define 	stdin 			(&_iob[0])
#define 	stdout 			(&_iob[1])
#define 	stderr 			(&_iob[2])

enum _flags {
		_READ 	= 	01,
		_WRITE 	= 	02,
		_UNBUF 	= 	04,
		_EOF 	= 	010,
		_ERR 	= 	020
};

int _fillbuff(FILE *);
int _flustbuf(int, FILE *);

#define 	feof(p) 		(((p)->flag & _EOF ) != 0)
#define 	ferror(p) 		(((p)->flag & _ERR ) != 0)
#define  	fileno(p) 		((p)->fd)

#define 	getc(p) 		(--(p)->cnt >= 0 \
				? (unsigned char) *(p)->ptr++ : _fillbuff(p))

#define 	putc(x,p) 		(--(p)->cnt >= 0 \
				? *(p)->ptr++ = (x) : _flustbuf((x), p)

#define 	getchar() 		getc(stdin)
#define 	putchar(x) 		putc((x), stdout)
