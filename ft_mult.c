/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:49:41 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/07 21:50:54 by mbalon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			mult_to_letter(char *result, char a)
{
	int			i;
	int			n;
	int			tmp;

	i = 0;
	tmp = 0;
	while (result[i])
	{
		n = ((result[i]) - '0') * (a - '0');
		result[i] = (n + tmp) % 10 + '0';
		tmp = (n + tmp) / 10;
		i++;
	}
	if (tmp != 0)
		result[i++] = (char)(tmp + '0');
	result[i] = '\0';
}

static	void	add_mult_to_letter_to_result(const char *s, char a,
													char *result, int j)
{
	int			i;
	int			n;
	unsigned	tens;
	unsigned	tmp;

	i = 0;
	tens = 0;
	a -= '0';
	while (s[i])
	{
		n = (s[i] - '0') * a;
		tmp = result[i + j] != '\0' ? result[i + j] - '0' + n + tens : n + tens;
		tens = (tmp * 205) >> 11;
		result[i + j] = tmp - ((tens << 3) + (tens << 1)) + '0';
		i++;
	}
	while (tens != 0)
	{
		tmp = result[i + j] != '\0' ? result[i + j] - '0' + tens : tens;
		tens = (tmp * 205) >> 11;
		result[i + j] = tmp - ((tens << 3) + (tens << 1)) + '0';
		i++;
	}
	result[i + j] = '\0';
}

static int		inner_cicle(const char *s1, const char *s2, char *result, int i)
{
	int			j;
	char		a;
	unsigned	tens;
	unsigned	tmp;

	j = 0;
	tens = 0;
	a = s2[i] - '0';
	while (s1[j])
	{
		tmp = result[i + j] + (s1[j] - '0') * a + tens;
		tens = (tmp * 205) >> 11;
		result[i + j] = tmp - ((tens << 3) + (tens << 1));
		j++;
	}
	while (tens != 0)
	{
		tmp = result[i + j] + tens;
		tens = (tmp * 205) >> 11;
		result[i + j] = tmp - ((tens << 3) + (tens << 1));
		j++;
	}
	return (j);
}

void			mult_to_char(const char *s1, const char *s2, char *result)
{
	int				i;
	int				j;

	i = 0;
	while (s2[i])
	{
		j = inner_cicle(s1, s2, result, i);
		i++;
	}
	result[i + j] = '\0';
	i--;
	while (i > 0)
	{
		i--;
		result[i + j] += '0';
	}
	while (j > 0)
	{
		j--;
		result[j] += '0';
	}
}

void			mult_to_int(const char *str, unsigned long long nbr,
														char *result)
{
	int i;

	i = 0;
	while (nbr > 0 || (i == 0 && nbr == 0))
	{
		add_mult_to_letter_to_result(str, (char)((nbr % 10) + '0'), result, i);
		i++;
		nbr /= 10;
	}
}
