#include "libftprintf.h"
#include <stdlib.h>


#include <stdio.h>
void fill_e_digits(char *str, int order, t_specification spec, char *decimal)
{
	int i;
	char *exp;
	int prec_counter;

	i = 0;
	str[i++] = decimal[0];
	if (spec.precision != 0)  
		str[i++] = '.';
	prec_counter = -1;
	while(++prec_counter < spec.precision && decimal[i - 1] != '\0')
	{
		str[i] = decimal[i - 1];
		i++;
	}
	while(++prec_counter <= spec.precision)
		str[i++] = '0';
	str[i++] = 'e';
	str[i++] = order < 0 ? '-' : '+';
	if (order < 10 && order > -10)
		str[i++] = '0';
	if (order < 0)
		exp = ft_longitoa(-order);
	else 
		exp = ft_longitoa(order);
	ft_strncpy(str + i, exp, ft_strlen(exp));
	free(exp);
}

int ft_float_e_rounding(char *decimal, int precision)
{
	int r_check;
	int len;

	len = ft_strlen(decimal);
	r_check = len - 2 - precision;
	if (r_check >= 0 && r_check < len)
	{
		if ((decimal[r_check] == '5' && ((decimal[r_check + 1] != '\0' && ((decimal[r_check + 1] - '0') % 2)) || not_empty_end(decimal, r_check) || decimal[r_check + 1] == '\0'))
			|| (decimal[r_check] > '5' && decimal[r_check] <= '9'))
		{
			decimal[r_check] = '0';//зачем
			if (r_check == len - 1)
			{
				decimal[len] = '1';
				return (1);
			}
			else
				decimal[r_check + 1]++;
			r_check++;
		}
		while (decimal[r_check] == 58)
		{
			decimal[r_check] = '0';
			if (r_check == len - 1)
			{
				decimal[len] = '1';
				return (1);
			}
			else
				decimal[r_check + 1]++;
			r_check++;	
		}
	}
	return (0);
}

#include <stdio.h>
char *print_e_float(t_floating_point fp, t_specification *spec, 
							char *decimal, int order)
{
	char *str;
	int num_digits;
	int filled_space;
	unsigned int count_digit;

	if(!spec->precision_set)
		spec->precision = 6;
	order +=ft_float_e_rounding(decimal, spec->precision);
	reversestr(decimal);
	num_digits = (spec->precision != 0 || spec->alt_print) ? 4 : 3;//e +int part +  sign_exp + common
	num_digits += spec->precision;//order поместиться ли?
	count_digit = (order < 0) ? ft_count_digit(-order) : ft_count_digit(order);
	num_digits += (count_digit > 1) ? count_digit : 2;
	if (fp.sign || spec->force_sign || spec->force_spacing)
		num_digits++;
	if (spec->minwidth < num_digits)
		spec->minwidth = num_digits;
	if (!(str = (char *)malloc(sizeof(char) * spec->minwidth + 1)))
		return (NULL);
	filled_space = fill_space(str, num_digits, spec, fp);
	fill_e_digits(str + filled_space, order, *spec, decimal);
	return(str);
}