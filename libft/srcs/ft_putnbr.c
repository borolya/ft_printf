/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:22:09 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 19:02:44 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned int	i;
	char			tmp;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 1;
	while (n / i > 9)
		i = i * 10;
	while (i > 0)
	{
		tmp = n / i + '0';
		n = n % i;
		write(1, &tmp, 1);
		i = i / 10;
	}
}
