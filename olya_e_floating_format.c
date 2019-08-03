#include "libftprintf.h"

#include <stdlib.h>

#include <stdio.h>
size_t					ft_e_float_format(char **pdst, t_specification spec,
							va_list ap)
{
	double				nbr;
	t_floating_point	fp;
	char                *decimal;
	int					order;
	
	nbr = va_arg(ap, double);
    ft_fill_floating_point(nbr, &fp);
    if (fp.nan || fp.inf)
        return (print_float_nan_or_inf(pdst, spec, fp));
    order = where_comma(fp, &decimal, spec);
    order = -order + ft_strlen(decimal) - 1;
	*pdst = print_e_float(fp, &spec, decimal, order);
	if (*pdst == NULL)
		return (0);
	free(decimal);
	return (spec.minwidth);
}