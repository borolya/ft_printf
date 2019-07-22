/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:24:04 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 20:24:47 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char	*src_char;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_char = (unsigned char*)dst;
	src_char = (const unsigned char*)src;
	i = 0;
	while (i < len)
	{
		if (src <= dst)
			dst_char[len - i - 1] = src_char[len - i - 1];
		else
			dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
