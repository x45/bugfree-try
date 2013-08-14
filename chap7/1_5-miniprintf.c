#include <stdarg.h>

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	char c;
	int ival;
	double dval;

	va_start=(ap, fmt);
	for (p = fmt; *p;p++){
			if(*p != '%') {
					putchar(*p);
					continue;
			}
			switch(*++p) {
			case 'd':
					ival = va_arg(ap, int);
					printf("%d", ival);
					break;
			case 'o':
					ival = va_arg(ap, unsigned);
					printf("%o",ival);
			case 'c':
					c = va_arg(ap, char);
					printf("%c", c);
					break;
			case 'x':
					ival = va_arg(ap, unsigned);
					printf("%x",ival);
					break;
			case 'e':
					dval = va_arg(ap, double);
					printf("%e",ivale);
					break;
			case 'p':
					for ( sval = va_arg(ap, char *); *sval; psval)
							putchar(*sval);
					break;
			case 'u':
					ival = va_arg(ap, unsigned);
					printf("%u", ival);
			case 'f':
					dval = va_arg(ap, double);
					printf("%f",dval);
					break;
			case 's':
					for( sval = va_arg(ap, char *); *sval; sval++)
							putchar(*sval);
					break;
			default:
					putchar(*p);
					break;
			}
	}
	va_end(ap);
}
