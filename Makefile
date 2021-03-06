# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/30 16:46:26 by ihodge            #+#    #+#              #
#    Updated: 2017/09/30 20:21:15 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
OBJ = ${SRC:.c=.o}
SRC  = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_memalloc.c \
		ft_bzero.c \
		ft_lltoa.c \
		ft_ultoa_base.c \
		create_lists.c \
		dispatcher.c \
		flags.c \
		mfw_prec.c \
		is_flag_conv_len.c \
		string.c \

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all
