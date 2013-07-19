#include <stdio.h>
int main()
{
	     float fahr, celsius;
	     float lower, upper, step;

	     printf("il fait chaud !chaud! et will! chemise ouverte chaine en or qui brille!lol\n");

	     lower = 0;//MaVariableIci
	     upper = 300;//MaVaviableIci
	     step = 20;//MaVariableIci

	     printf(" ***C***\t***F***\n");
	     fahr = lower;
	     while (fahr <= upper) {
		     celsius = (5.0/9.0) * (fahr-32.0);
		     printf ("%8.2f %14.2f\n",fahr, celsius);//F=float ,nombre a virgule.
		     fahr += step;
	     }
	         return 0;
}
