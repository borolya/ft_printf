#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_specifier
{
    char flag;
    int width;
    int precision;
    char format;
    char type;
}   t_specifier;

#endif