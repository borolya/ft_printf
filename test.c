//#include "libftprintf.h"
#include <stdio.h>
#include <math.h>
int main (void)
{
	double d;
	unsigned long  byte[2];
	unsigned long int b;
	void *tmp;

	tmp = (void *)&d;

	d = sqrt(-5);
	b = *((unsigned long *)&d);
	byte[0] = *((unsigned long *)tmp);
	byte[1] = *((unsigned long *)(tmp + 8));

	printf("%p\n", tmp);
	printf("%p\n", &(byte[0]));
	printf("%p\n", &(byte[1]));
	printf("%p\n", (tmp + 8));
	printf("%lu\n", sizeof(byte[0]));
	printf("%ld\n", byte[0]);
	printf("%ld\n", byte[1]);
	printf("%f\n", d);

	//printf ("printf = %d", printf("re |%.99Lf|\n", d));
	//printf(t_printf = %d", ft_printf("my |%.99Lf|\n", d));
	return (0);
}
