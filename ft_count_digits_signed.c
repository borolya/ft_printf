/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_signed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbalon-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:50:21 by mbalon-s          #+#    #+#             */
/*   Updated: 2019/08/07 18:50:23 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_cds(long long int nbr)
{
	int		res;

	res = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}
