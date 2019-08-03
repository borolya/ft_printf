#include "libftprintf.h"

void reversestr(char *s)
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

 void sum_str_with_shift(char *result, char *term, int j)
 {
	int i;

	i = 0;
	while (term[i] || result[i + j] >= '9')
	{
		if (result[i + j] == '\0')
			result[i + j] = '0';
		if (term[i] != '\0')
			result[i + j] += term[i] - '0';
		if (result[i + j] > '9')
		{
			result[i + j] -= 10;
			if (result[i + j + 1] != '\0')
				result[i + j + 1]++;
			else
				result[i + j] = '1';
		}
		i++;
	}
	result[i] = '\0';
 }

void mult_to_letter(char *result, char a)
{
	int i;
	int n;
	int tmp;

  	i = 0;
	tmp = 0;
	while (result[i])
	{
		n =  ((result[i]) - '0') * (a - '0');
		result[i] = (n  + tmp) % 10 + '0';
		tmp = (n + tmp) / 10;
		i++;
	}
	if (tmp != 0)
		result[i++] = (char)(tmp + '0');
	result[i] = '\0';
}

static void add_mult_to_letter_to_result(const char *s, char a, char *result, int j)
{
	int i;
	int n;
	int tens;
	int tmp;

  	i = 0;
	tens = 0;
	while (s[i])
	{
		n =  ((s[i]) - '0') * (a - '0');
		if (result[i + j] != '\0')
			tmp = result[i + j] - '0' + n  + tens;
		else 
			tmp = n + tens;
		result[i + j] = tmp % 10 + '0';
		tens = tmp / 10;
		i++;
	}
	while (tens != 0)
	{
		if (result[i + j] != '\0')
			tmp = result[i + j] - '0'  + tens;
		else 
			tmp = tens;
		result[i + j] = tmp % 10 + '0';
		tens = tmp / 10;
		i++;
	}
	result[i + j] = '\0';
}

void mult_to_char(const char *s1, const char *s2, char *result)
{
	int i;

	i = 0;
	while(s2[i])
	{
		add_mult_to_letter_to_result(s1, s2[i], result, i);
		i++;
	}
}

void mult_to_int(const char *str, unsigned long long nbr, char *result)
{
	int i;

	i  = 0;
	while(nbr > 0 || (i == 0 && nbr == 0))
	{
		add_mult_to_letter_to_result(str, (char)((nbr % 10) + '0'), result, i);
		i++;
		nbr /= 10;
	}
}