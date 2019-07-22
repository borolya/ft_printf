#include "ft_printf.h"

init(t_spec *spec)
{
	spec->min_flag = 0;
}

int expected_type(char *str, t_spec *spec)
{
	if (*str == csp || *str == diouxX || *str == '%')
	{
		spec->type = ft_strnew(&(*(str)));;
		return (1);
	}
	return (0); 
}

int expected_format(char *str, t_spec *spec)
{
	if (*str == 'l' || *str == 'h' || *str == 'L')
	{
		str++;
		if (*str == 'l' && *(str - 1) == 'l')
		{
			str++;
			 spec->format = ft_strnew("ll");
		}
		else if(*str == 'h' && *(str - 1) == 'h')
		{
			str++;
			spec->format = ft_strnew("hh");
		}
		else 
			spec->format = ft_strnew(&(*(str - 1)));//not right
	}
	return (expect_type(str, spec));
}

int expected_precision(char *str, t_spec *spec)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			spec->precision = -1;
			str++;
			return (expected_format(str, spec));
		}
		if (*str >= 0 && *str <= '9')
		{
			spec->pretision = ft_atoi(str);
			while (*str >= 0 && *str <= '9')
				str++;
			return (expected_format(str, spec));
		}	
	}
	return (expected_format(str, spec));
}

int	expected_width(char *str, t_spec *spec)
{
	if (*str == '*')
	{
		spec->width = -1;
		str++;
		return (expected_precision(str, spec));
	}

	if (*str >= 0 && *str <= '9')
	{
		spec->width = ft_atoi(str);
		while (*str >= 0 && *str <= '9')
			str++;
		return (expected_precision(str, spec));
	}
	return (expected_precision(str, spec));
}

int expected_flag(char *str)//вернуть конец str
{
	t_spec *spec;
	char *s;

	st = str;
	if (!(spec = ft_memmalloc(sizeof(t_spec)))
		return (0);
	init (spec);
	while (*st == '+' || *st == '-' || *st == ' ' || *st ==  '#' || *st == '0')//nuul 
	{
		if (*st == '+')
			spec->pl_flag = 1;
		else if (*st == '-')
			spec->min_flag = 1;
		else if (*st == ' ')
			spec->sp_flag = 1;
		else if (*st == '#')
			spec->hash_flag = 1;
		else if (*st == '0')
			spec->null_flag = 1;
		st++;//
	}
	return (expect_width(st, spec));
}

int ft_printf(const char *str, ...)
{
	int count;

	while (*str != '/0')
	{
		if (*str == '%')
			expected_flag(&str);//pinter to *
		else write(1, str, 1);//f tckb yt yf[jlbn?]
		str++;
		//add list
	}
}

#include <stdio.h>

int main()
{
	printf("|sdsfd %*10.*s|",  10, 2, "dfdf");
		return (0);
}