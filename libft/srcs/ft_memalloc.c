/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:52:20 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 16:35:59 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;
	char	*mem_ch;

	if (!(mem = malloc(size)))
		return (NULL);
	mem_ch = (char*)mem;
	i = 0;
	while (i < size)
	{
		mem_ch[i] = 0;
		i++;
	}
	return (mem);
}
