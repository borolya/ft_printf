#include "libftprintf.h"

size_t					ft_e_float_format(char **pdst, t_specification spec,
							va_list ap)
{
	double				nbr;
	t_floating_point	fp;
	t_smartstr          *smart;
	int					order;
	
	nbr = va_arg(ap, double);
    ft_fill_floating_point(nbr, &fp);
    if (fp.nan || fp.inf)
        return (printf_float_nan_or_inf(pdst, spec, fp));
    if (!(smart = ft_memalloc(sizeof(t_smartstr))))
        return (0);
    order = where_comma(fp, smart);
    order--;
	*pdst = print_e_float(fp, &spec, *smart, order);
	if (*pdst == NULL)
		return (0);
	free(smart->str);
	free(smart);
	return (spec.minwidth);
}