/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_ft_decimal_notation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:33:49 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 19:54:03 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libftprintf.h"

void		exponentiation(unsigned int iter, char base, char **tmp,
														char **mult_str)
{
	int		count;
	void	*p;

	count = 32;
	while ((iter & 0x80000000) == 0 && count > 0)
	{
		iter <<= 1;
		count--;
	}
	ft_strcpy(*mult_str, &base);
	while (count > 1)
	{
		mult_to_char(*mult_str, *mult_str, *tmp);
		p = *mult_str;
		*mult_str = *tmp;
		*tmp = p;
		ft_bzero(*tmp, ft_strlen(*tmp));
		count--;
		iter <<= 1;
		if (iter & 0x80000000)
			mult_to_letter(*mult_str, base);
	}
}

static int	integer_case_helper(t_floating_point fp,
								char **decimal)
{
	char			*tmp;

	tmp = ft_longitoa(fp.f);
	ft_reversestr(tmp);
	*decimal = tmp;
	return (0);
}

static int	integer_case(t_floating_point fp, char **decimal,
												int fraction_digit)
{
	unsigned int	iter;
	char			*mult_str;
	char			*tmp;
	int				size;

	iter = fp.e - fraction_digit;
	size = iter + ft_count_digit(fp.f) + 3;
	if (iter == 0)
		return (integer_case_helper(fp, decimal));
	if (!(mult_str = ft_memalloc(sizeof(char) * size)))
	{
		*decimal = NULL;
		return (0);
	}
	if (!(tmp = ft_memalloc(sizeof(char) * size)))
	{
		free(mult_str);
		*decimal = NULL;
		return (0);
	}
	exponentiation(iter, '2', &tmp, &mult_str);
	mult_to_int(mult_str, fp.f, tmp);
	*decimal = tmp;
	free(mult_str);
	return (0);
}

static int	fraction_case(t_floating_point fp, char **decimal,
												int fraction_digit)
{
	unsigned int	iter;
	char			*mult_str;
	char			*tmp;
	int				size;

	iter = fraction_digit - fp.e;
	size = iter + ft_count_digit(fp.f) + 3;
	if (!(mult_str = ft_memalloc(sizeof(char) * size)))
	{
		*decimal = NULL;
		return (0);
	}
	if (!(tmp = ft_memalloc(sizeof(char) * size)))
	{
		free(mult_str);
		*decimal = NULL;
		return (0);
	}
	exponentiation(iter, '5', &tmp, &mult_str);
	mult_to_int(mult_str, fp.f, tmp);
	*decimal = tmp;
	free(mult_str);
	return (fraction_digit - fp.e);
}

int			where_comma(t_floating_point fp, char **decimal,
									t_specification spec)
{
	int fraction_digit;

	if (spec.long_double_mod == 1)
		fraction_digit = 63;
	else
		fraction_digit = 52;
	if (spec.long_double_mod != 1 && fp.integer != 0)
		fp.f |= 0x10000000000000;
	if (fp.e < fraction_digit)
		return (fraction_case(fp, decimal, fraction_digit));
	return (integer_case(fp, decimal, fraction_digit));
}
