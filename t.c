#include "libftprintf.h"
#include <stdio.h>
#include <float.h>

int main()
{
	double d;
	void	*addr;

	d = 0.008;

	printf("re  = |%.2g|\n", d);
	printf("\n");
	//ft_printf("my  = |%.7g|\n", d);
	return (0);
}
