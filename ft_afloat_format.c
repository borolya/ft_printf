/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afloat_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:32:52 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/08/07 18:45:47 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf.h"

static int				count_digits_fraction(unsigned long long fr)
{
	int		res;

	res = 0;
	while (fr != 0)
	{
		fr &= 0x0FFFFFFFFFFFF;
		fr <<= 4;
		res++;
	}
	return (res);
}

static size_t			print_afloat_nan_or_inf(char **pdst,
												t_specification spec,
												int is_nan)
{
	int		len;
	char	*str;
	char	*arg;

	if (is_nan)
		arg = "nan";
	else
		arg = "#inf";
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

size_t					ft_afloat_format(char **pdst, t_specification spec,
										va_list ap)
{
	double				nbr;
	int					num_digits;
	char				*str;
	t_floating_point	fp;

	nbr = va_arg(ap, double);
	ft_fill_floating_point(nbr, &fp);
	if (fp.nan || fp.inf)
		return (print_afloat_nan_or_inf(pdst, spec, fp.nan));
	if (!spec.precision_set && !(fp.f == 0 && fp.e == 0))
		spec.precision = count_digits_fraction(fp.f);
	num_digits = 3 + spec.precision + 2;
	num_digits += fp.e && (fp.f || fp.e != -1023) ? ft_cds(fp.e) : 1;
	num_digits += 1;
	if (fp.sign || spec.force_sign || spec.force_spacing)
		num_digits++;
	if (spec.minwidth < num_digits)
		spec.minwidth = num_digits;
	str = (char *)malloc(sizeof(char) * spec.minwidth + 1);
	if (str == NULL)
		return (0);
	str[spec.minwidth] = '\0';
	ft_print_afloat(fp, spec, str, num_digits);
	*pdst = str;
	return (spec.minwidth);
}
