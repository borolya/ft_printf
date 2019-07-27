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

static size_t			print_float_nan_or_inf(char **pdst,
												t_specification spec,
												t_floating_point num)
{
	int		len;
	char	*str;
	char	*arg;

	if (num.nan)
		arg = "nan";
	else if (num.sign)
		arg = "-inf";
	else if (spec.force_sign)
		arg = "+inf";
	else if (spec.force_spacing)
		arg = " nan";
	else
		arg = "inf";
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

size_t					ft_float_format(char **pdst, t_specification spec,
							va_list ap)
{
	double				nbr;
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