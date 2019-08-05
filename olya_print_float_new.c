
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libftprintf.h"



static int integer_case(t_floating_point fp, char **decimal, int fraction_digit)
{
	unsigned int iter;
	char *mult_str;
	char *tmp;
	int count;
	int size;

	iter = fp.exponent - fraction_digit;
	size = iter + ft_count_digit(fp.fraction) + 3;
	*decimal = ft_memalloc(sizeof(char) * size);//error
	mult_str = *decimal;
	if (iter == 0)
	{
		tmp = ft_longitoa(fp.fraction);
		reversestr(tmp);
		*decimal = tmp;
		return (0);
	}
	tmp = ft_memalloc(sizeof(char) * size);//error
	count = 32;
	while ((iter & 0x80000000) == 0 && count > 0)
	{
		iter<<=1;
		count--;
	}
	ft_strcpy(mult_str, "2");
	while (count > 1)
	{
		mult_to_char(mult_str, mult_str, tmp);
		ft_strcpy(mult_str, tmp);
		ft_bzero(tmp, size);
		count--;
		iter <<= 1;
		if (iter & 0x80000000)
			mult_to_letter(mult_str, '2');
	}
	mult_to_int(mult_str, fp.fraction, tmp);
	ft_strcpy(mult_str, tmp);
	free(tmp);
	return (0);
}

static int fraction_case(t_floating_point fp, char **decimal, int fraction_digit)
{
	unsigned int iter;
	char *mult_str;
	char *tmp;
	int count;
	int size;

	iter = fraction_digit - fp.exponent;
	size = iter + ft_count_digit(fp.fraction) + 3;
	
	*decimal = ft_memalloc(sizeof(char) * size);//if error
	tmp = ft_memalloc(sizeof(char) * size);
	mult_str = *decimal;
	count = 32;
	while ((iter & 0x80000000) == 0 && count > 0)
	{
		iter <<=1;
		count--;
	}
	ft_strcpy(mult_str, "5");
	while (count > 1)
	{
		mult_to_char(mult_str, mult_str, tmp);
		ft_strcpy(mult_str, tmp);
		ft_bzero(tmp, size);
		count--;
		iter <<= 1;
		if (iter & 0x80000000)
			mult_to_letter(mult_str, '5');
	}
	mult_to_int(mult_str, fp.fraction, tmp);
	ft_strcpy(mult_str, tmp);
	free(tmp);
	return (fraction_digit - fp.exponent);
}

int	where_comma(t_floating_point fp, char **decimal, t_specification spec)
{
	int fraction_digit;

	if (spec.long_double_mod == 1)
		fraction_digit = 63;
	else 
		fraction_digit = 52;
	if (spec.long_double_mod != 1 && fp.integer != 0)
		fp.fraction |= 0x10000000000000;
	if (fp.exponent < fraction_digit)
		return (fraction_case(fp, decimal, fraction_digit));
	return (integer_case(fp, decimal, fraction_digit));
}

static void fill_digit(char *str, char *decimal, t_specification spec, int order)
{
	int i;
	int j;
	int k;

	i = 0;
	if (order > 0)
	{
		ft_strncpy(str, decimal, order);
		i +=order;
		if (spec.precision != 0 || spec.alt_print)
		str[i++] = '.';
		j = 0;
		while (j < spec.precision && decimal[order + j] != '\0')
		{
			str[j + i] = decimal[order + j];
			j++;
		}
	}
	else 
	{
		str[i++] = '0';
		if (spec.precision != 0 || spec.alt_print)
			str[i++] = '.';
		j = 0;
		while (++order <= 0 && j < spec.precision)
		{
			str[j + i] = '0';
			j++;
		}
		k = 0;
		while (j < spec.precision && decimal[order + j] != '\0')
		{
			str[j + i] = decimal[order + k - 1];
			k++;
			j++;
		}
	}
	while (j < spec.precision && spec.specificator != G_FLOAT)
	{
		str[j + i] = '0';
		j++;
	}
}

int fill_space(char *str, int num_digits, t_specification *spec, t_floating_point fp)
{
	int i;

	str[spec->minwidth] = '\0';
	ft_memset(str, ' ', spec->minwidth);
	if (spec->force_zeroes && spec->align_left)
		ft_memset(str, '0', num_digits);
	else if (spec->force_zeroes)
		ft_memset(str, '0', spec->minwidth);
	if (spec->align_left || spec->force_zeroes)
		i = 0;
	else
		i = spec->minwidth - num_digits;
	if (fp.sign)
		str[i++] = '-';
	else if (spec->force_sign)
		str[i++] = '+';
	else if (spec->force_spacing)
		str[i++] = ' ';
	if (spec->force_zeroes)
		i += spec->minwidth - num_digits;
	return (i);
}

int not_empty_end(const char *str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (str[i] != '0')
			return (1);
		i++;
	}	
	return (0);
}

int ft_float_rounding(char *decimal, int comma, int r_check)
{
	//int r_check;
	int lenstr;

	lenstr = ft_strlen(decimal);
	//r_check = comma - precision - 1;
	if (r_check >= 0 && r_check < lenstr)
	{
		/*  && (decimal[r_check + 1] - '0') % 2 == 1 */
		if ((decimal[r_check] == '5' && ((decimal[r_check + 1] != '\0' && ((decimal[r_check + 1] - '0') % 2)) || not_empty_end(decimal, r_check) || decimal[r_check + 1] == '\0'))
			|| (decimal[r_check] > '5' && decimal[r_check] <= '9'))
		{
			decimal[r_check] = '0';
			if (r_check == lenstr - 1 || decimal[r_check + 1] < '0' || decimal[r_check + 1] > '9')
			{
				decimal[lenstr] = '1';
				lenstr++;
			}
			else
				(decimal[r_check + 1])++;
			r_check++;
		}
		while (decimal[r_check] == '9' + 1)
		{
			decimal[r_check] = '0';
			if (r_check == lenstr - 1)
			{
				decimal[lenstr] =  '1';
				lenstr++;
			}
			else
				(decimal[r_check + 1])++;
			r_check++;	
		}
	}
	return (lenstr - comma);
}

char *print_float(t_floating_point fp, t_specification *spec, char *decimal, int comma)
{
	int num_digits;
	char *str;
	int filled_space;
	int order;

	if (!spec->precision_set)
		spec->precision = 6;
	order = ft_float_rounding(decimal, comma, comma - spec->precision - 1);
	reversestr(decimal);
	num_digits = order > 0 ? order : 1;
	num_digits += (spec->precision == 0 && !spec->alt_print)  ? 0 : 1;
	num_digits += spec->precision;
	if (fp.sign || spec->force_sign || spec->force_spacing)
		num_digits++;
	if (spec->minwidth < num_digits)
		spec->minwidth = num_digits;
	if (!(str = (char *)malloc(sizeof(char) * spec->minwidth + 1)))
		return (NULL);
	filled_space = fill_space(str, num_digits, spec, fp);
	fill_digit(str + filled_space, decimal, *spec, order);
	return (str);
}