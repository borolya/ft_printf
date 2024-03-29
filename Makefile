NAME = libftprintf.a
CC = gcc

CFLAGS =  -Wall -Werror -Wextra -I . -c

SOURCES = ft_printf.c			        \
		  ft_getstrbyspec.c		        \
		  ft_smartstrncat.c		        \
		  ft_expandsmartstr.c	        \
		  ft_flushsmartstr.c	        \
		  ft_strchr.c			        \
		  ft_strcpy.c			        \
		  ft_instr.c			        \
		  ft_ulfromstr.c		        \
		  ft_memset.c			        \
		  ft_bzero.c			        \
		  ft_strlen.c			        \
		  ft_strncpy.c			        \
		  ft_count_digits_unsigned.c    \
		  ft_getspecificator.c	        \
		  ft_get_signed_arg.c           \
		  ft_get_unsigned_arg.c         \
		  ft_percent_format.c	        \
		  ft_unknown_format.c	        \
		  ft_char_format.c		        \
		  ft_string_format.c	        \
		  ft_unicode_format.c           \
		  ft_integer_format.c	        \
		  ft_oct_format.c		        \
		  ft_hex_format.c		        \
		  ft_unsigned_format.c	        \
		  ft_pointer_format.c			\
		  ft_afloat_format.c			\
		  ft_utf8_count_bytes.c			\
		  ft_utf8_convert.c				\
		  ft_format_hex.c				\
		  ft_count_digits_signed.c		\
          ft_fill_floating_point.c \
		  ft_float_format.c		\
		  ft_libft.c					\
		  ft_mult.c					\
		  ft_print_float.c			\
		  ft_e_floating_format.c		\
		  ft_print_e_float.c			\
		  ft_g_float_format.c			\
		  ft_decimal_notation.c	\
		  ft_float_rounding.c		\
		  ft_toupper.c					\
		  ft_print_afloat.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = $(NAME:.a=.h)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I ./libft/includes $< 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
