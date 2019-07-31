#include "libftprintf.h"
#include <stdlib.h>


#include <stdio.h>
void fill_e_digits(char *str, int order, t_specification spec, t_smartstr smart)
{
    int i;
    char *exp;
    int prec_counter;

    i = 0;
    str[i++] = smart.str[0];
    if (spec.precision != 0)  
        str[i++] = '.';
    prec_counter = -1;
    //printf("str = %s\n", smart.str);
    while(++prec_counter < spec.precision && smart.str[i - 1] != '\0')
    {
        str[i] = smart.str[i - 1];
        i++;
        //printf("char str = %c, char smart = %c\n", str[i], str[i-1]);
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
    ft_strcpy(str + i, exp);
    free(exp);
}

int ft_float_e_rounding(t_smartstr *smart, int precision)
{
    int r_check;

    r_check = smart->len - 2 - precision;
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
    return (0);
}

#include <stdio.h>
char *print_e_float(t_floating_point fp, t_specification *spec, 
                            t_smartstr smart, int order)
{
    char *str;
    int num_digits;
    int filled_space;
    unsigned int count_digit;

    if(!spec->precision_set)
        spec->precision = 6;
    order +=ft_float_e_rounding(&smart, spec->precision);
    reversestr(smart.str);
    num_digits = spec->precision == 0 ? 3 : 4;//e +int part +  sign + common
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
    fill_e_digits(str + filled_space, order, *spec, smart);
    return(str);
}