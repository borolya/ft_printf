#include "libftprintf.h"
#include <stdio.h>

int main (void)
{
	long double d;

	d = 0x0.000002p0;
	printf("%lu", sizeof(long double));
	//printf ("printf = %d", printf("re |%.99Lf|\n", d));
	//printf("ft_printf = %d", ft_printf("my |%.99Lf|\n", d));
	return (0);
}
