/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:16:32 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 16:41:38 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str_eq(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		if (check_str_eq(haystack, needle) == 1)
			return ((char*)haystack);
		haystack++;
	}
	if (check_str_eq(haystack, needle) == 1)
		return ((char*)haystack);
	return (NULL);
}
