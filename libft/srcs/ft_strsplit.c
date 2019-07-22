/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:21:53 by bharmund          #+#    #+#             */
/*   Updated: 2019/01/27 22:03:07 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_all(char **array, int string_numb)
{
	int i;

	i = 0;
	while (i < string_numb)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static	int		string_count(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	if (s[0] != '\0' && s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static	char	*take_string(char const *s, char c, int i)
{
	int		count;
	char	*str;
	int		j;

	count = 0;
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		count++;
		j++;
	}
	if (!(str = (char*)malloc(sizeof(char) * count + 1)))
		return (NULL);
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**array;
	int		string_numb;

	if (!s)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (string_count(s, c) + 1))))
		return (NULL);
	string_numb = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && (i == 0 || (i != 0 && s[i - 1] == c)))
		{
			array[string_numb] = take_string(s, c, i);
			if (array[string_numb] == NULL)
			{
				free_all(array, string_numb);
				return (NULL);
			}
			string_numb++;
		}
	}
	array[string_numb] = NULL;
	return (array);
}
