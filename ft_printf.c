/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/29 17:07:55 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	save_signs(t_format *format, char c)
{
	if (c == ' ')
		format->space = 1;
	else if (c == '+')
		format->plus = 1;
	else if (c == '-')
		format->minus = 1;
	else if (c == '#')
		format->alternate = 1;
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
		save_signs(format, *str);
		str++;
	}
}

void	write_arg(va_list ap, t_format *format, char conv)
{
	if (conv == 'i' || conv == 'd' || conv == 'D')
		ft_putstr(dispatcher(format, va_arg(ap, long long)));
	if (conv == 'u' || conv == 'o' || conv == 'x' || conv == 'X' ||
			conv == 'p')
		ft_putstr(u_dispatcher(format, va_arg(ap, unsigned long)));
	if (conv == 'c' || conv == 'C')
		ft_putchar((unsigned char)va_arg(ap, int));
	if (conv == 's' || conv == 'S')
		ft_putstr(string_conv(format, va_arg(ap, char *)));
}

int		process_arg(va_list ap, char *str, int *length, t_format *format)
{
	int i;
	int len;

	i = 1;
	if (*(str + 1) == '%')
	{
		ft_putchar(str[i]);
		return (i + 1);
	}
	format = create_format();
	save_flag(format, (char*)str + 1);
	while (is_flag(str[i]))
		i++;
	str += i;
	len = is_length((char*)str, format);
	str = str + len;
	i += len;
	if (is_conv(*str) == 1)
	{
		format->conv = *str;
		write_arg(ap, format, *str);
		(*length) += format->strlength;
		str++;
		i++;
		free(format);
	}
	else if (*str != '%')
		return (1);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_format	*format;
	int			length;

	format = NULL;
	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += process_arg(ap, (char*)str, &length, format);
		}
		else if (*str)
		{
			ft_putchar(*str);
			length++;
			str++;
		}
	}
	va_end(ap);
	return (length);
}
