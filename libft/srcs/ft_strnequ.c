/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:44:30 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 16:53:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (!s1[i] || !s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			else
				return (1);
		}
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
