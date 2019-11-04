/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_print_e_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:19:36 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 19:48:35 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	fill_e_digits(char *str, int order, t_specification spec, char *decimal)
{
	int		i;
	char	*exp;

	i = 0;
	str[i++] = decimal[0];
	if (spec.precision != 0 || spec.alt_print)
		str[i++] = '.';
	while (0 < spec.precision && decimal[i - 1] != '\0')
	{
		str[i] = decimal[i - 1];
		spec.precision--;
		i++;
	}
	while (0 <= --spec.precision &&
		(spec.specificator != G_FLOAT || spec.alt_print))
		str[i++] = '0';
	str[i++] = spec.long_long_mod == 1 ? 'E' : 'e';
	str[i++] = order < 0 ? '-' : '+';
	if (order < 10 && order > -10)
		str[i++] = '0';
	exp = order < 0 ? ft_longitoa(-order) : ft_longitoa(order);
	ft_strncpy(str + i, exp, ft_strlen(exp));
	free(exp);
	free(decimal);
}

char	*take_e_decimal_float(t_floating_point fp, t_specification *spec)
{
	char	*decimal;
	int		order;
	int		len;
	int		comma;

	comma = where_comma(fp, &decimal, *spec);
	if (decimal == NULL)
		return (NULL);
	len = ft_strlen(decimal);
	order = len - comma - 1;
	if (!spec->precision_set)
		spec->precision = 6;
	if (ft_float_rounding(decimal, len - 2 - spec->precision) > len)
		order++;
	ft_reversestr(decimal);
	return (print_e_float(fp, spec, decimal, order));
}

char	*print_e_float(t_floating_point fp, t_specification *spec,
							char *decimal, int order)
{
	char			*str;
	int				num_digits;
	int				filled_space;
	unsigned int	count_digit;

	num_digits = (spec->precision != 0 || spec->alt_print) ? 4 : 3;
	num_digits += spec->precision;
	count_digit = (order < 0) ? ft_count_digit(-order) : ft_count_digit(order);
	num_digits += (count_digit > 1) ? count_digit : 2;
	if (fp.sign || spec->force_sign || spec->force_spacing)
		num_digits++;
	if (spec->minwidth < num_digits)
		spec->minwidth = num_digits;
	if (!(str = (char *)malloc(sizeof(char) * spec->minwidth + 1)))
		return (NULL);
	filled_space = fill_space(str, num_digits, spec, fp);
	fill_e_digits(str + filled_space, order, *spec, decimal);
	return (str);
}
