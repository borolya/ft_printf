/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:12:37 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/09 15:00:30 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (save);
}
