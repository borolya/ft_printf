/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:30:58 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/29 17:04:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst != '\0')
	{
		if (i < size)
			i++;
		dst++;
	}
	while (size > 0 && i < size - 1 && *src != '\0')
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	if (i != size)
		*dst = '\0';
	while (*src != '\0')
	{
		i++;
		src++;
	}
	return (i);
}
