/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_ft_fill_floating_point.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:00:26 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/08/07 18:37:29 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					ft_fill_floating_point(double nbr,
												t_floating_point *dst)
{
	unsigned long int	byte_repr;

	byte_repr = *((unsigned long *)&nbr);
	dst->sign = (byte_repr >> 63) & 0x1;
	dst->e = ((byte_repr >> 52) & 0x7FF) - 1023;
	dst->f = byte_repr & 0xFFFFFFFFFFFFF;
	dst->integer = 1;
	dst->nan = dst->e == 1024 && dst->f != 0 ? 1 : 0;
	dst->inf = dst->e == 1024 && dst->f == 0 ? 1 : 0;
	if (dst->e == -1023 && dst->f == 0)
	{
		dst->integer = 0;
		dst->e = 0;
	}
	else if (dst->e == -1023)
	{
		while (!(dst->f & 0x8000000000000))
		{
			dst->f <<= 1;
			dst->e--;
		}
		dst->f <<= 1;
		dst->f &= 0xFFFFFFFFFFFFFFFF;
	}
}

void					ft_fill_long_floating_point(long double nbr,
												t_floating_point *dst)
{
	unsigned long int	byte_repr[2];
	void				*adr;

	adr = (void*)&nbr;
	byte_repr[0] = *((unsigned long*)adr);
	byte_repr[1] = *((unsigned long*)(adr + 8));
	dst->sign = (byte_repr[1] >> 15) & 0x1;
	dst->e = (byte_repr[1] & 0x7FFF) - 16383;
	dst->f = byte_repr[0] & 0x7FFFFFFFFFFFFFFF;
	dst->nan = dst->e == 16384 && dst->f != 0 ? 1 : 0;
	dst->inf = dst->e == 16384 && dst->f == 0 ? 1 : 0;
	dst->f = byte_repr[0] & 0xFFFFFFFFFFFFFFFF;
	if (dst->e == -16383 && dst->f == 0)
		dst->e = 0;
	else if (dst->e == -16383)
	{
		while (!(dst->f & 0x8000000000000))
		{
			dst->f <<= 1;
			dst->e--;
		}
		dst->f <<= 1;
		dst->f &= 0xFFFFFFFFFFFFFFFF;
	}
}
