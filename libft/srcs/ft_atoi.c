/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:02:50 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 22:04:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	space_free(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
							|| str[i] == '\r' || str[i] == '\n'
							|| str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	sg;
	int				start;

	res = 0;
	start = space_free(str);
	i = start;
	sg = 1;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
							(i == start && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			sg = -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((((res * 10) + sg * (str[i] - 48)
				- sg * (str[i] - 48)) / 10) != res)
				return (sg == 1 ? -1 : 0);
			else
				res = (res * 10) + sg * (str[i] - 48);
		}
		++i;
	}
	return (res);
}
