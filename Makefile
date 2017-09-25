# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/30 16:46:26 by ihodge            #+#    #+#              #
#    Updated: 2017/09/25 11:54:36 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
OBJ = ${SRC:.c=.o}
SRC  = ft_isdigit.c \
		ft_itoa.c \
		ft_printf.c \
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
		ft_strdel.c \
		ft_lltoa.c \
		create_lists.c \
		dispatcher.c \
		main.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all
