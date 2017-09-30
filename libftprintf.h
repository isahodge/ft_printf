/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:39:51 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/30 16:24:12 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct		s_format
{
	char			conv;
	char			length;
	int				space;
	int				plus;
	int				minus;
	int				alternate;
	int				zero;
	int				mfw;
	int				precision;
	int				strlength;
}					t_format;

union				u_data_union
{
	unsigned int	uint;
	unsigned char	uchar;
	unsigned short	ushort;
	unsigned long	ulong;
	size_t			usizet;
	uintmax_t		uintmaxt;
};

//int					ft_isdigit(int c);
int					ft_printf(const char *str, ...);
void				ft_putchar(char c);
char				*ft_itoa(int n);
void				ft_putstr(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
t_format			*create_format(void);
char				*dispatcher(t_format *format, long long data);
char				*u_dispatcher(t_format *format, unsigned long data);
char				*plus_flag(char *str, long long data);
char				*space_flag(char *str, long long data);
char				*min_field_wid(char *str, t_format *format);
void				fill_after(char *str, char **result, int fill);
void				fill_before(char *str, char **result, int fill,
		char character);
char				*int_precision(char *str, int precision);
char				*negative_int(char *str, long long data);
char				*ft_lltoa(long long n);
char				*ft_ultoa_base(union u_data_union du, t_format *format,
		unsigned int base);
char				*fptr_with_length(char c, char l, long long *data);
char				*ufptr_with_length(t_format *format, unsigned long *data);
char				*alt_flag(char *str, t_format *format);
int					is_flag(char c);
int					is_conv(char c);
int					is_length(char *str, t_format *format);
char				*string_conv(t_format *format, char *str);
char				*str_precision(char *str, int precision);
char				*mfw_char(char *str, t_format *format);
void				write_arg(va_list ap, t_format *format, char conv);
char				*char_conv(t_format *format, unsigned char c);
#endif
