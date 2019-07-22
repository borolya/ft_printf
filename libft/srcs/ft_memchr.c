/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:02:19 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/29 17:01:36 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;

	s_char = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s_char[i] == (unsigned char)c)
			return (s_char + i);
		i++;
	}
	return (NULL);
}
