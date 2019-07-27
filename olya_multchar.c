#include <stdlib.h>
#include <stdio.h>
//#include "libft.h"
#include <stddef.h>
#include "libftprintf.h"



static void reversechar(char *s)
{
	int l;
	int i;
	char tmp;

	l = ft_strlen(s);
	i = 0;
	while (i < l/2)
	{
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
		i++;
	}
}


static void sum_char(t_smartstr *smart, const char *term, int j)//all reverse
{
	int i;

	if (!smart || !smart->str)
		return ;
	
	i = 0;
	while (term[i] || smart->str[i + j] >= '9')
	{
		if (smart->str[i + j] == '\0')
			ft_smartstrncat(smart, "0", 1);
		if (term[i] != '\0')
			smart->str[i + j] += term[i] - '0';
		if (smart->str[i + j] > '9')
		{
			smart->str[i + j] -= 10;
			if (smart->str[i + j + 1] != '\0')
				smart->str[i + j + 1]++;
			else 
				ft_smartstrncat(smart, "1", 1);
		}
		i++;
	}
}

static char *mult_to_letter(char *s, char a)
{
	int i;
	int n;
	char *tmp;
	t_smartstr *smart;

	smart = ft_memalloc(sizeof(t_smartstr));
	ft_smartstrncat(smart, "0", 1);
  	i = 0;
	while (s[i])
	{
		n =  ((s[i]) - '0') * (a - '0');
		tmp = ft_longitoa(n);
		reversechar(tmp);
		sum_char(smart, tmp, i);
		free(tmp);
		i++;
	}
	tmp = ft_strdup(smart->str);
	free(smart->str);
	free(smart);
	return (tmp);
}

char *mult_and_free(char *s1,  char *s2)//better if s1 longer//
{
	t_smartstr *mult;
	int i;
	char *tmp;

	reversechar(s1);
	reversechar(s2);
	mult = ft_memalloc(sizeof(t_smartstr));
	ft_smartstrncat(mult, "0", 1);
	i = 0;
	while (s2[i])
	{
		tmp = mult_to_letter(s1, s2[i]);
		sum_char(mult, tmp, i);
		free(tmp);
		i++;
	}
	reversechar(mult->str);
	tmp = ft_strdup(mult->str);
	free(mult->str);
	free(mult);
	free(s1);
	free(s2);
	return (tmp);
}
