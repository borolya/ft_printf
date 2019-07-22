/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:49:41 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 22:03:37 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest_c;
	unsigned char	*src_c;

	i = 0;
	dest_c = (unsigned char*)dest;
	src_c = (unsigned char*)src;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		if (src_c[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
