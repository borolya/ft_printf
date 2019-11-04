/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_e_floating_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:25:05 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 15:25:08 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t					ft_e_float_format(char **pdst, t_specification spec,
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
	*pdst = take_e_decimal_float(fp, &spec);
	if (*pdst == NULL)
		return (0);
	return (spec.minwidth);
}
