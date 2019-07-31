#include "libftprintf.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

int main (void)
{
	double d;

	d = 7.;
	printf("re = %Lf\n", LDBL_MIN);
	ft_printf("my = %Lf\n", LDBL_MIN);

	return (0);
}
