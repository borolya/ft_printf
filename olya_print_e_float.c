#include "libftprintf.h"

int ft_count_digit(unsigned long long int nbr)
{
    int digit;

    digit = 1;
    while (nbr /= 10 > 0)
    return (nbr);
}


void fill_digits(char *str, int order, t_specification spec, t_smartstr smart);
{
    int i;
    char *exp;
    i = 0;
    str[i] = smart->str[0];
    if (spec->precision != 0)
        str[i++] = '.';
    while(i - 1 < spec->precision && smart.str[i] != '\0')
        str[i++] = smart.str[i - 1];
    while(i - 1 < spec->precision)
        str[i++] = '0';
    str[i++] = 'e';
    str[i++] = order < 0 ? '-' : '+';
    if (order < 10 && order > -10)
        str[i++] = '0';
    if (order < 0)
        exp = ft_longitoa(-order);
    else 
        exp = ft_longitoa(order);
    ft_strcpy(str, exp);
    free(exp);
}



char *print_e_float(t_floating_point fp, t_specification *spec, 
                            t_smartstr smart, int order)
{
    char *str;
    int num_digits;
    int filled_space;
    char *exp;
    unsigned int count_digit;

    if(!spec->precision_set)
        spec->precision = 6;
    num_digits = spec->precision == 0 ? 4 : 3;//e +int part +  sign + common
    num_digits += spec->precision;
    count_digit = (order < 0) ? ft_count_digit(-order) : ft_count_digit(order);
    num_digits += (count_digit > 1) ? count_digit : 2;
    if (fp.sign || spec->force_sign || spec->force_spacing)
		num_digits++;
	if (spec->minwidth < num_digits)
		spec->minwidth = num_digits;
	if (!(str = (char *)malloc(sizeof(char) * spec->minwidth + 1)))
		return (NULL);
    filled_space = fill_space(str, num_digits, spec, fp);
    fill_digits(str + filled_space, order, *spec, smart);
    return(str);
}