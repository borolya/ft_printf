/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:15:44 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 22:02:12 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char			*str;
	unsigned int	count;
	unsigned int	i;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	count = 0;
	while (s[count])
		count++;
	if (count != 0)
	{
		while (s[count - 1] && (s[count - 1] == ' '
				|| s[count - 1] == '\t' || s[count - 1] == '\n'))
			count--;
	}
	if (!(str = malloc(count + 1)))
		return (NULL);
	i = -1;
	while (++i < count)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
