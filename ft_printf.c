/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/25 11:28:35 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	save_str(char *start_str, char **string)
{
	int			len;

	len = 0;
	if (start_str)
	{
		if (*start_str == '%')
			len++;
		while (start_str[len] != '%' && start_str[len] != '\0')
			len++;
		start_str = ft_strsub(start_str, 0, len);
		if ((*string) == NULL)
			(*string) = start_str;
		else
			(*string) = ft_strjoin((*string), start_str);
	}
}

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
	t_flag *flags;
	int		num;

	flags = format->flag;
	while (*str != '\0' && is_flag(*str) >= 1)
	{
		if (*str == '.')
		{
			flags->flag = '.';
			str++;
		}
		if (is_flag(*str) == 2)
		{
			num = 0;
			if (*str == '0')
				flags->flag = '0';
			while (is_flag(*str) == 2)
			{
				if (!flags->flag)
					flags->flag = 'm';
				num = num * 10 + *str - '0';
				flags->num = num;
				str++;
			}
		}
		else 
		{
			flags->flag = *str;
			str++;
		}
		flags->next = create_flag();
		flags = flags->next;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		 ap;
	char		*string;
	t_format	*format;

	format = NULL;
	string = NULL;
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
				ft_putstr(dispatcher(format, va_arg(ap, long long)));
				str++;
			}
			else if (*str != '%')
				return (0);
			format = format->next;
		}
		ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (0);
}
