#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

size_t					ft_long_float_format(char **pdst, t_specification spec,
							va_list ap)
{
    long double nbr;
    t_floating_point	fp;
	t_smartstr          *smart;
	int					order;
	
	nbr = va_arg(ap, double);
	ft_fill_floating_point(nbr, &fp);
	if (fp.nan || fp.inf)
		return (print_float_nan_or_inf(pdst, spec, fp));
	smart = ft_memalloc(sizeof(t_smartstr));
	order = where_comma(fp, smart);
	*pdst = print_float(fp, &spec, smart, order);
	if (*pdst == NULL)
		return (0);
	free(smart->str);
	free(smart);
	return (spec.minwidth);

}