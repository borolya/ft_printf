/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:10:55 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/03/04 15:23:11 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

void	ft_upper_nan_or_inf(char **arg, t_floating_point num,
											t_specification spec)
{
	if (num.nan)
		*arg = "NAN";
	else if (num.sign)
		*arg = "-INF";
	else if (spec.force_sign)
		*arg = "+INF";
	else if (spec.force_spacing)
		*arg = " NAN";
	else
		*arg = "INF";
}

void	ft_lower_nan_or_inf(char **arg, t_floating_point num,
											t_specification spec)
{
	if (num.nan)
		*arg = "nan";
	else if (num.sign)
		*arg = "-inf";
	else if (spec.force_sign)
		*arg = "+inf";
	else if (spec.force_spacing)
		*arg = " nan";
	else
		*arg = "inf";
}

size_t	ft_print_float_nan_or_inf(char **pdst, t_specification spec,
												t_floating_point num)
{
	int		len;
	char	*str;
	char	*arg;

	if (spec.long_long_mod)
		ft_upper_nan_or_inf(&arg, num, spec);
	else
		ft_lower_nan_or_inf(&arg, num, spec);
	len = ft_strlen(arg);
	spec.precision = len;
	if (spec.minwidth < spec.precision)
		spec.minwidth = spec.precision;
	str = (char *)malloc(sizeof(char) * (spec.minwidth + 1));
	if (str == NULL)
		return (0);
	ft_memset(str, ' ', spec.minwidth);
	str[spec.minwidth] = '\0';
	*pdst = str;
	str = spec.align_left ? str : str + spec.minwidth - spec.precision;
	ft_strncpy(str, arg, spec.precision);
	return (spec.minwidth);
}

size_t	ft_float_format(char **pdst, t_specification spec, va_list ap)
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
	*pdst = ft_take_decimal_float(fp, &spec);
	if (*pdst == NULL)
		return (0);
	return (spec.minwidth);
}
