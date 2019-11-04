/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspecificator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <mbalon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:33:46 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/08/07 19:03:17 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static size_t		additional_getspecificator(const char *format,
										t_specification *pspec)
{
	size_t	res;

	res = 1;
	if (*format == '%')
		pspec->specificator = PERCENT;
	else if (*format == 'x' || *format == 'X')
		pspec->specificator = HEX;
	else if (*format == 'p')
		pspec->specificator = POINTER;
	else if (*format == 'a' || *format == 'A')
		pspec->specificator = A_FLOAT;
	else if (*format == 'f' || *format == 'F')
		pspec->specificator = FLOAT;
	else if (*format == 'e' || *format == 'E')
		pspec->specificator = E_FLOAT;
	else if (*format == 'g' || *format == 'G')
		pspec->specificator = G_FLOAT;
	else
	{
		pspec->specificator = UNKNOWN;
		pspec->ch = *format;
		return (*format == '\0' ? 0 : 1);
	}
	return (res);
}

size_t				ft_getspecificator(const char *format,
										t_specification *pspec)
{
	size_t	res;

	res = 1;
	if (*format == 'D' || *format == 'O' || *format == 'U' || *format == 'C' ||
		*format == 'S' || *format == 'F' || *format == 'E' || *format == 'G' ||
		*format == 'A')
		pspec->long_long_mod = 1;
	if (*format == 'A' || *format == 'X' || *format == 'E' || *format == 'G' ||
		*format == 'F')
		pspec->upper = 1;
	else
		pspec->upper = 0;
	if (*format == 'c' || *format == 'C')
		pspec->specificator = CHAR;
	else if (*format == 's' || *format == 'S')
		pspec->specificator = STRING;
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		pspec->specificator = INTEGER;
	else if (*format == 'o' || *format == 'O')
		pspec->specificator = OCT;
	else if (*format == 'u' || *format == 'U')
		pspec->specificator = UNSIGNED;
	else
		return (additional_getspecificator(format, pspec));
	return (res);
}
