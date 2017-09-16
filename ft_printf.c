/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/15 16:44:51 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*save_str(char *start_str)
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
}

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == '%' || c == ' ')
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
		if (is_flag(*str) == 2)
		{
			num = 0;
			if (*str == '0')
				flags->flag = '0';
			while (is_flag(*str) == 2)
			{
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
	return (ft_strlen(string));
}

			//printf("format->conv = %c\n", format->conv);
			//printf("format->flag->flag = %c\n", format->flag->flag);
			//printf("format->flag->next->flag = %c\n", format->flag->next->flag);
			//if (format->flag->num != 0)
			//	printf("format->flag->int = %i\n", format->flag->num);

//dDioOxXuU all can be promoted to long

/*int		ft_printf(const char *str, ...)
{
	va_list ap;
	char	*string;
	//t_flag 	*flags;

	//flags = NULL;
	string = save_str((char*)str);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			//flags = create_flag();
			str++;
			if (is_integer(str) == 1)
				string = save_str(ft_itoa(va_arg(ap, long)));//using just itoa is not sustainable.
			else
				break ;
			str++;
			if (*str != '%')
				string = save_str((char*)str);
		}
		str++;
	}
	va_end(ap);
	ft_putstr(string);
	return (0);//supposed to return the length of final string.
}*/
