#include "libftprintf.h"
#include <stdlib.h>
static char	*fill(unsigned long long int i, unsigned long long int n, char *str)
{
	int j;

	j = 0;
	while (i > 0)
	{
		str[j] = n / i + '0';
		n = n % i;
		i = i / 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}
//change 
char *ft_longitoa(unsigned long long int n)//unsigned
{
	char			*str;
	unsigned long long int	i;
	unsigned int		count;

	count = 0;
	i = 1;
	while (n / i > 9)
	{
		i = i * 10;
		count++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (count + 1 + 1))))
		return (NULL);
	return (fill( i, n, str));
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
