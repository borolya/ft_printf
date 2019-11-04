/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:37:50 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 15:37:53 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int		ft_count_digit(unsigned long long int nbr)
{
	int digit;

	digit = 1;
	while ((nbr /= 10) > 0)
		digit++;
	return (digit);
}

void	ft_reversestr(char *s)
{
	int		l;
	int		i;
	char	tmp;

	l = ft_strlen(s);
	i = 0;
	while (i < l / 2)
	{
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
		i++;
	}
}

char	*ft_longitoa(unsigned long long int n)
{
	char	*str;
	int		count;

	count = ft_count_digit(n);
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	while (--count >= 0)
	{
		str[count] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

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
