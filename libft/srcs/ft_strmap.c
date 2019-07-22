/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:42:48 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 18:09:20 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
