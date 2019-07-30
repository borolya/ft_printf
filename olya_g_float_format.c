#include "libftprintf.h"
#include <stdarg.h>

size_t  ft_float_g_format(char **pdst, t_specification spec, 
								va_list ap)
{
	double nbr;

	nbr = va_arg(ap, double);
	ft_fill_floating_point(nbr, &fp);
	if (fp.nan || fp.inf)
		return (print_float_nan_or_inf(pdst, spec, fp));
	if (!(smart = ft_memalloc(sizeof(t_smartstr))))
		return (0);
	if ()
}						