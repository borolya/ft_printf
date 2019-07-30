#include "libftprintf.h"
#include <stdlib.h>


#include <stdio.h>
int ft_count_digit(unsigned long long int nbr)
{
	int digit;

	digit = 1;
	
	while ((nbr /= 10) > 0)
		digit++;
	return (digit);
}

char *ft_longitoa(unsigned long long int n)//unsigned
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
