/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_afloat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:43:34 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/08/07 18:48:47 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void				promote(char *str)
{
	while (*str == 'g' || *str == '.')
	{
		if (*str != '.')
		{
			*str += '0' - 'g';
			if (str[-1] != '.')
			{
				str[-1] += 1;
				if (str[-1] == '9' + 1)
					str[-1] = 'a';
			}
			else
			{
				str[-2] += 1;
				if (str[-2] == '9' + 1)
					str[-2] = 'a';
			}
		}
		str--;
	}
}

static size_t			fill_decimal(char *dst,
										unsigned long long fr,
										int count)
{
	int		digit;
	char	*tmp;

	tmp = dst;
	while (count > 1)
	{
		digit = (fr & 0xF000000000000) >> 48;
		fr = (fr & 0xFFFFFFFFFFFF) << 4;
		*tmp = digit >= 10 ? 'a' + digit - 10 : '0' + digit;
		tmp++;
		count--;
	}
	if (count != 0)
	{
		digit = (fr & 0xF000000000000) >> 48;
		fr &= 0xFFFFFFFFFFFF;
		if ((fr >= 0x810000000000 && ((fr >> 40) & 0x1)) ||
			(fr >= 0x900000000000))
			digit++;
		*tmp = digit >= 10 ? 'a' + digit - 10 : '0' + digit;
		if (*tmp == 'g')
			promote(tmp);
		tmp++;
	}
	return (tmp - dst);
}

static size_t			print_afloat_preface(t_floating_point fp,
												t_specification spec, char *str,
												int num_digits)
{
	size_t				i;

	ft_memset(str, ' ', spec.minwidth);
	if (spec.force_zeroes && spec.align_left)
		ft_memset(str, '0', num_digits);
	else if (spec.force_zeroes)
		ft_memset(str, '0', spec.minwidth);
	if (spec.align_left || spec.force_zeroes)
		i = 0;
	else
		i = spec.minwidth - num_digits;
	if (fp.sign)
		str[i++] = '-';
	else if (spec.force_sign)
		str[i++] = '+';
	else if (spec.force_spacing)
		str[i++] = ' ';
	ft_strncpy(str + i, "0x", 2);
	i += 2;
	return (i);
}

void					ft_print_afloat(t_floating_point fp,
										t_specification spec, char *str,
										int num_digits)
{
	size_t				i;
	int					digits;

	i = print_afloat_preface(fp, spec, str, num_digits);
	if (spec.force_zeroes)
		i += spec.minwidth - num_digits;
	if (fp.integer == 0)
		ft_strncpy(str + i, "0", 1);
	else
		ft_strncpy(str + i, "1", 1);
	i += 1;
	if (spec.precision != 0)
		str[i++] = '.';
	i += fill_decimal(str + i, fp.f, spec.precision);
	str[i++] = 'p';
	str[i++] = fp.e >= 0 ? '+' : '-';
	fp.e = fp.e < 0 ? -fp.e : fp.e;
	digits = ft_cds(fp.e);
	digits += digits == 0 ? 1 : 0;
	while (digits > 0)
	{
		digits--;
		str[i + digits] = '0' + fp.e % 10;
		fp.e /= 10;
	}
}
