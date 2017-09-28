# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/30 16:46:26 by ihodge            #+#    #+#              #
#    Updated: 2017/09/27 18:47:09 by ihodge           ###   ########.fr        #
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

all: $(NAME)

$(NAME): $(OBJ)
	@#gcc $(FLAGS) $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
