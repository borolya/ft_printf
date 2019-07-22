# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:28:57 by bharmund          #+#    #+#              #
#    Updated: 2019/07/18 18:34:50 by bharmund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c -Wall -Wextra -Werror
SOURCE = 	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strdup.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_memalloc.c \
					ft_memdel.c \
					ft_strnew.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					get_next_line.c

OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SOURCE))
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_LIST))
HEADER_DIR = ./includes/
HEADER = $(addprefix $(HEADER_DIR), libft.h)
SRCDIR = srcs/
SRC = $(addprefix $(SRCDIR), $(SOURCE))
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar src $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRCDIR)%.c $(HEADER) 
	$(CC) -I$(HEADER_DIR) $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NANE)

re: fclean all
