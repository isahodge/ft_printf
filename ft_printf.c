/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/27 20:42:52 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == ' ' || c == '.' ||
			c == 'm')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

int		is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'o' || c == 'O' ||
			c == 'u' || c == 'U' || c == 'D' || c == 'p')
		return (1);
	return (0);
}

int		is_length(char *str, t_format *format)
{
	if ((*str == 'h' && *(str + 1) == 'h') && is_conv(*(str + 2)))
	{
		format->length = 'H';
		return (2);
	}
	else if ((*str == 'l' && *(str + 1) == 'l') && is_conv(*(str + 2)))
	{
		format->length = 'X';
		return (2);
	}
	else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z')
			&& is_conv(*(str + 1)))
	{
		format->length = *str;
		return (1);
	}
	return (0);
}

void	save_flag(t_format *format, char *str)
{
	int		num;

	while (*str != '\0' && is_flag(*str) >= 1)
	{
		if (*str == '.')
			format->precision = 1;
		if (is_flag(*str) == 2)
		{
			num = 0;
			if (*str == '0' && !format->precision)
				format->zero = 1;
			while (is_flag(*str) == 2)
			{
				num = num * 10 + *str - '0';
				str++;
			}
			str--;
			if (format->precision)
				format->precision = num;
			else
				format->mfw = num;
		}
		else if (*str == ' ')
			format->space = 1;
		else if (*str == '+')
			format->plus = 1;
		else if (*str == '-')
			format->minus = 1;
		else if (*str == '#')
			format->alternate = 1;
		str++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		 ap;
	t_format	*format;
	int			length;

	format = NULL;
	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format = create_format();
			save_flag(format, (char*)str);
			while (is_flag(*str))
				str++;
			str = str + is_length((char*)str, format);
			if (is_conv(*str) == 1)
			{
				format->conv = *str;
				if (*str == 'i' || *str == 'd')
					ft_putstr(dispatcher(format, va_arg(ap, long long)));
				if (*str == 'u' || *str == 'o' || *str == 'x' || *str == 'X')
					ft_putstr(u_dispatcher(format, va_arg(ap, unsigned long)));
				length += format->strlength;
				str++;
			}
			else if (*str != '%')
				return (0);
			free(format);
		}
		if (*str)
		{
			ft_putchar(*str);
			length++;
			str++;
		}
	}
	va_end(ap);
	return (length);
}
