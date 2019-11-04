/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_ft_float_roundind.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:36:08 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/06 21:36:12 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			not_empty_end(const char *str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int			ft_float_rounding(char *decimal, int check)
{
	int lenstr;

	lenstr = ft_strlen(decimal);
	if (check >= 0 && check < lenstr)
	{
		if ((decimal[check] == '5' &&
		(not_empty_end(decimal, check) || decimal[check + 1] == '\0'
		|| (decimal[check + 1] != '\0' && ((decimal[check + 1] - '0') % 2))))
		|| (decimal[check] > '5' && decimal[check] <= '9'))
		{
			(decimal[check + 1])++;
			check++;
		}
		while (decimal[check] == '9' + 1 || decimal[check] == 1)
		{
			decimal[check] = decimal[check] == 1 ? '1' : '0';
			if (check != lenstr)
				(decimal[check + 1])++;
			else
				lenstr++;
			check++;
		}
	}
	return (lenstr);
}
