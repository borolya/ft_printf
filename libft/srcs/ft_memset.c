/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:01:10 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/29 17:29:22 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;
	size_t			i;

	b_char = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = (unsigned char)(c);
		i++;
	}
	return (b);
}
