
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libftprintf.h"



static int integer_case(t_floating_point fp, t_smartstr *smart, int fraction_digit)
{
	int iter;

	iter = fp.exponent - fraction_digit;
	if (iter == 0)
	{
		smart->str = ft_longitoa(fp.fraction);
		return (0);
	}
	ft_smartstrncat(smart, "2", 1);
	reversestr(smart->str);
	while (--iter > 0)
	{
		if(mult_and_free(smart, ft_strdup("2")))
			exit(1);

	}   
	if(mult_and_free(smart, ft_longitoa(fp.fraction)))
			exit(1);
	//ft_rounding(smart, &spec);
   // reversestr(smart->str);
	return (0);
}

static int fraction_case(t_floating_point fp, t_smartstr *smart, int fraction_digit)
{
	int iter;

	iter = fraction_digit - fp.exponent;
	ft_smartstrncat(smart, "5", 1);
	reversestr(smart->str);
	while (--iter > 0)
	{
		if(mult_and_free(smart, ft_strdup("5")))//mult_to_letter
			exit(1);
	}
	if (mult_and_free(smart, ft_longitoa(fp.fraction)))
		exit(1);
	return (fraction_digit - fp.exponent);
}

int	where_comma(t_floating_point fp, t_smartstr *smart, t_specification spec)
{
	int fraction_digit;

	if (spec.long_double_mod == 1)
		fraction_digit = 63;
	else 
		fraction_digit = 52;
	if (spec.long_double_mod != 1 && fp.integer != 0)
		fp.fraction |= 0x10000000000000;
	if (fp.exponent < fraction_digit)
		return (fraction_case(fp, smart, fraction_digit));
	return (integer_case(fp, smart, fraction_digit));
}

static void fill_digit(char *str, t_smartstr *smart, t_specification spec, int order)
{
	int i;
	int j;
	int k;

	i = 0;
	if (order > 0)
	{
		ft_strncpy(str, smart->str, order);
		i +=order;
		if (spec.precision != 0 || spec.alt_print)
		str[i++] = '.';
		j = 0;
		while (j < spec.precision && smart->str[order + j] != '\0')
		{
			str[j + i] = smart->str[order + j];
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
		while (j < spec.precision && smart->str[order + j] != '\0')
		{
			str[j + i] = smart->str[order + k - 1];
			k++;
			j++;
		}
	}
	while (j < spec.precision)
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

int ft_float_rounding(t_smartstr *smart, int comma, int precision)
{
	int r_check;
	
	r_check = comma - precision - 1;
	if (r_check > 0 && (unsigned long)r_check < smart->len)
	{
		if ((smart->str[r_check] == '5' && smart->str[r_check] != '\0' && (smart->str[r_check] - '0') % 2 == 1)
			|| (smart->str[r_check] > '5' && smart->str[r_check] <= '9'))
		{
			smart->str[r_check] = '0';
			if ((unsigned long)r_check == smart->len - 1)
				ft_smartstrncat(smart, "1", 1);
			else
				smart->str[r_check + 1]++;
			r_check++;
		}
		while (smart->str[r_check] == 58)
		{
			smart->str[r_check] = '0';
			if ((unsigned long)r_check == smart->len - 1)
				ft_smartstrncat(smart, "1", 1);
			else
				smart->str[r_check + 1]++;
			r_check++;	
		}
	}
	return (smart->len - comma);
}

char *print_float(t_floating_point fp, t_specification *spec, t_smartstr *smart, int comma)
{
	int num_digits;
	char *str;
	int filled_space;
	int order;

	if (!spec->precision_set)
		spec->precision = 6;
	order = ft_float_rounding(smart, comma, spec->precision);
	reversestr(smart->str);
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
	fill_digit(str + filled_space, smart, *spec, order);
	return (str);
}