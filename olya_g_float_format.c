#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
size_t  ft_g_float_format(char **pdst, t_specification spec, 
								va_list ap)
{
	double 				nbr;
	t_floating_point 	fp;
	int 				comma;
	char          		*decimal;
	int					order;

	nbr = va_arg(ap, double);
	ft_fill_floating_point(nbr, &fp);
	if (fp.nan || fp.inf)
		return (print_float_nan_or_inf(pdst, spec, fp));
	comma = where_comma(fp, &decimal, spec);
	order = ft_strlen(decimal) - comma;
	if (order < -4 || order > spec.precision)

		spec.precision--;
		*pdst = print_e_float(fp, &spec, decimal, order - 1);
	else 
	{	
		*pdst = print_g_float(fp, &spec, decimal, comma);
	}
	if (*pdst == NULL)
		return (0);
	free(decimal);
	return (spec.minwidth);
}						    

char *print_g_float(t_floating_point fp, t_specification *spec, char *decimal, int comma)
{
    int order;

    if (!spec->precision_set)
		spec->precision = 6;
    order = ft_float_rounding(decimal, comma, ft_strlen(decimal) - spec->precision - 1);
    reversestr(decimal);
    
}