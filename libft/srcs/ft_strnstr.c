/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:36:45 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/29 16:24:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_str_eq(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] == '\0')
		return (1);
	else
		return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (check_str_eq(big + i, little, len - i) == 1)
			return ((char*)(big + i));
		i++;
	}
	if (check_str_eq(big, little, len) == 1)
		return ((char*)(big));
	return (NULL);
}
