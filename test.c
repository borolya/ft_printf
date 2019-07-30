#include "libftprintf.h"
#include <stdio.h>
#include <math.h>
int main (void)
{
	
	//printf("%s", ft_longitoa(3453524));
	printf("{%f}{%lf}{%Lf}\n", 1.6465424242242454654, -144456544464.6465424242242454654, -144456544464.6465424242242454654l);
	//printf("
	ft_printf("{%f}{%lf}{%Lf}\n", 1.42, -144456544464.6465424242242454654, -144456544464.6465424242242454654l);
	//printf("%.2f\n", 10.4555);
	//ft_printf("%.2f\n", 10.4555);
	return (0);
}
