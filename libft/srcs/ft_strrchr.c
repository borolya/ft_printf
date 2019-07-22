/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:13:25 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 16:41:05 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s)
	{
		if (*s == (char)c)
			save = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (save);
}
