/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:39:51 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/15 20:42:28 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_flag
{
	struct s_flag	*next;
	int				num;
	char			flag;
}					t_flag;

typedef	struct		s_format
{
	struct s_format	*next;
	char			*result;
	char			conv;
	t_flag			*flag;
}					t_format;

char				*(*fptr[127]) (int data);
int					ft_isdigit(int c);
int					ft_printf(const char *str, ...);
void				ft_putchar(char c);
char				*ft_itoa(int n);
void				ft_putstr(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char* src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
t_flag				*create_flag(void);
t_format			*create_format(void);
char				*dispatcher(t_format *format, int data);
char				*plus_flag(char *str);
char				*space_flag(char *str);
int					check_if_flag(t_flag *flags, char match);
char				*min_field_wid(char *str, t_flag *flags, int num);
void				conv_funct_ptr(void);
#endif
