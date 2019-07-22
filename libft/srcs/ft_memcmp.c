/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:10:26 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 20:06:17 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char*)s1;
	s2_char = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1_char[i] - s2_char[i] == 0)
			i++;
		else
			return (s1_char[i] - s2_char[i]);
	}
	return (0);
}
