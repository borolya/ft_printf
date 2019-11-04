/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_print_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:28:25 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 19:48:40 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libftprintf.h"

static void	fill_digit_fraction_case(char *str, char *decimal,
									t_specification spec, int order)
{
	int i;
	int k;

	i = 0;
	str[i++] = '0';
	if (spec.precision != 0 || spec.alt_print)
		str[i++] = '.';
	while (++order <= 0 && spec.precision > 0)
	{
		str[i++] = '0';
		spec.precision--;
	}
	k = -1;
	while (spec.precision > 0 && decimal[++k] != '\0')
	{
		str[i++] = decimal[k];
		spec.precision--;
	}
	while (spec.precision > 0 &&
		(spec.specificator != G_FLOAT || spec.alt_print))
	{
		str[i++] = '0';
		spec.precision--;
	}
}

static void	fill_digit(char *str, char *decimal, t_specification spec,
																int order)
{
	int i;

	i = 0;
	if (order > 0)
	{
		ft_strncpy(str, decimal, order);
		i += order;
		if (spec.precision != 0 || spec.alt_print)
			str[i++] = '.';
		while (spec.precision > 0 && decimal[i - 1] != '\0')
		{
			str[i] = decimal[i - 1];
			i++;
			spec.precision--;
		}
		while (spec.precision > 0 &&
		(spec.specificator != G_FLOAT || spec.alt_print))
		{
			str[i++] = '0';
			spec.precision--;
		}
	}
	else
		fill_digit_fraction_case(str, decimal, spec, order);
	free(decimal);
}

int			fill_space(char *str, int num_digits, t_specification *spec,
												t_floating_point fp)
{
	int i;

	str[spec->minwidth] = '\0';
	ft_memset(str, ' ', spec->minwidth);
	if (spec->force_zeroes && spec->align_left)
		ft_memset(str, '0', num_digits);
	else if (spec->force_zeroes)
		ft_memset(str, '0', spec->minwidth);
	if (spec->align_left || spec->force_zeroes)
		i = 0;
	else
		i = spec->minwidth - num_digits;
	if (fp.sign)
		str[i++] = '-';
	else if (spec->force_sign)
		str[i++] = '+';
	else if (spec->force_spacing)
		str[i++] = ' ';
	if (spec->force_zeroes)
		i += spec->minwidth - num_digits;
	return (i);
}

char		*ft_take_decimal_float(t_floating_point fp, t_specification *spec)
{
	char	*decimal;
	int		len;
	int		comma;

	comma = where_comma(fp, &decimal, *spec);
	if (decimal == NULL)
		return (NULL);
	if (!spec->precision_set)
		spec->precision = 6;
	len = ft_float_rounding(decimal, comma - spec->precision - 1);
	ft_reversestr(decimal);
	return (ft_print_float(fp, spec, decimal, len - comma));
}

char		*ft_print_float(t_floating_point fp, t_specification *spec,
										char *decimal, int order)
{
	int		num_digits;
	char	*str;
	int		filled_space;

	num_digits = order > 0 ? order : 1;
	num_digits += (spec->precision == 0 && !spec->alt_print) ? 0 : 1;
	num_digits += spec->precision;
	if (fp.sign || spec->force_sign || spec->force_spacing)
		num_digits++;
	if (spec->minwidth < num_digits)
		spec->minwidth = num_digits;
	if (!(str = (char *)malloc(sizeof(char) * spec->minwidth + 1)))
		return (NULL);
	filled_space = fill_space(str, num_digits, spec, fp);
	fill_digit(str + filled_space, decimal, *spec, order);
	return (str);
}
