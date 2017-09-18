/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/17 20:29:13 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	save_str(char *start_str, char **string)
{
	int			len;

	len = 0;
	while (start_str[len] != '%' && start_str[len] != '\0')
		len++;
	start_str = ft_strsub(start_str, 0, len);
	if ((*string) == NULL)
		(*string) = start_str;
	else
		(*string) = ft_strjoin((*string), start_str);
}

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == '%' || c == ' ' || c == '.' ||
			c == 'm')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

int		is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'o' || c == 'O' ||
			c == 'u' || c== 'U' || c == 'D' || c == 'p')
		return (1);
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
	flags->next = NULL;
	if (is_conv(*str) == 1)
		format->conv = *str;
}

int		ft_printf(const char *str, ...)
{
	va_list		 ap;
	char		*string;
	t_format	*format;

	format = NULL;
	string = NULL;
	save_str((char*)str, &string);
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
			if (is_conv(*str) == 1)
				save_str(dispatcher(format, va_arg(ap, int)), &string);
			else
				break ;
			str++;
				save_str((char*)str, &string);
			format = format->next;
		}
		str++;
	}
	va_end(ap);
	ft_putstr(string);
	return (ft_strlen(string));
}

			//printf("format->conv = %c\n", format->conv);
			//printf("format->flag->flag = %c\n", format->flag->flag);
			//printf("format->flag->next->flag = %c\n", format->flag->next->flag);
			//if (format->flag->num != 0)
			//	printf("format->flag->int = %i\n", format->flag->num);

//dDioOxXuU all can be promoted to long

/*char	*save_str(char *start_str)
{
	static char *string;
	char		*tmp;
	int			len;

	len = 0;
	while (start_str[len] != '%' && start_str[len] != '\0')
		len++;
	if (string == NULL)
		string = ft_strnew(1);
	start_str = ft_strsub(start_str, 0, len);
	tmp = ft_strjoin(string, start_str);
	string = tmp;
	return (string);
}*/
/*int		ft_printf(const char *str, ...)
{
	va_list		 ap;
	char		*string;
	t_format	*format;
	int			string_len;

	format = NULL;
	printf("1\n");
	string = save_str((char*)str);
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
			if (is_conv(*str) == 1)
				string = save_str(dispatcher(format, va_arg(ap, int)));
			else
				break ;
			str++;
				string = save_str((char*)str);
			format = format->next;
		}
		str++;
	}
	va_end(ap);
	ft_putstr(string);
	string_len = ft_strlen(string);
	ft_strdel(&string);
	return (string_len);
}*/
