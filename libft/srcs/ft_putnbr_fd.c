/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:19:51 by bharmund          #+#    #+#             */
/*   Updated: 2018/12/28 19:03:53 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			tmp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	i = 1;
	while (n / i > 9)
		i = i * 10;
	while (i > 0)
	{
		tmp = n / i + '0';
		n = n % i;
		write(fd, &tmp, 1);
		i = i / 10;
	}
}
