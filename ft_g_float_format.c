/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_g_float_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:18:23 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 19:49:47 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

int		nonzero_part(const char *decimal, size_t start, size_t end)
{
	size_t len;

	len = ft_strlen(decimal);
	while (end != start && (end >= len || (end < len && decimal[end] == '0')))
		end--;
	if (start == end && start == '0')
		return (0);
	return (end - start + 1);
}

char	*take_g_decimal_float(t_floating_point fp, t_specification *spec)
{
	char	*decimal;
	int		order;
	int		comma;

	if (spec->precision == 0)
		spec->precision = 1;
	comma = where_comma(fp, &decimal, *spec);
	if (decimal == NULL)
		return (NULL);
	order = ft_float_rounding(decimal,
					ft_strlen(decimal) - spec->precision - 1) - comma;
	ft_reversestr(decimal);
	if (order < -4 || order > spec->precision)
	{
		spec->precision = spec->alt_print == 0 ? nonzero_part(decimal, 0,
							spec->precision - 1) - 1 : (spec->precision - 1);
		spec->precision = spec->precision < 0 ? 0 : spec->precision;
		order--;
		return (print_e_float(fp, spec, decimal, order));
	}
	spec->precision = spec->alt_print == 0 ? nonzero_part(decimal, 0,
					spec->precision - 1) - order : (spec->precision - order);
	if (spec->precision < 0)
		spec->precision = 0;
	return (ft_print_float(fp, spec, decimal, order));
}

size_t	ft_g_float_format(char **pdst, t_specification spec,
								va_list ap)
{
	long double			lnbr;
	double				nbr;
	t_floating_point	fp;

	if (spec.long_double_mod == 1)
	{
		lnbr = va_arg(ap, long double);
		ft_fill_long_floating_point(lnbr, &fp);
	}
	else
	{
		nbr = va_arg(ap, double);
		ft_fill_floating_point(nbr, &fp);
	}
	if (fp.nan || fp.inf)
		return (ft_print_float_nan_or_inf(pdst, spec, fp));
	if (!spec.precision_set)
		spec.precision = 6;
	*pdst = take_g_decimal_float(fp, &spec);
	if (*pdst == NULL)
		return (0);
	return (spec.minwidth);
}
