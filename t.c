#include "libftprintf.h"
#include <stdio.h>
#include <float.h>

int main()
{
	double d;
	void	*addr;

	d = 0.2465;

	printf("re  = |%-13e|\n", d);
	printf("\n");
	ft_printf("my  = |%-13e|\n", d);
	return (0);
}
