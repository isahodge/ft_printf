/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:16:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/23 17:51:02 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dispatcher(t_format *format, long long data)
{
	char	*result;
	t_flag	*flags;

	flags = format->flag;
	result = NULL;
	result = call_fptr_with_length(format->conv, format->length, &data);
	result = int_precision(result, format->flag);
	result = negative_int(result, data);
	while (flags)
	{
		if (flags->flag == '+')
			result = plus_flag(result, data);
		else if (flags->flag == ' ' && check_if_flag(format->flag, '+') == 0)
			result = space_flag(result, data);
		else if (flags->flag == '0' || flags->flag == 'm')
			result = min_field_wid(result, format->flag, flags->num);
		flags = flags->next;
	}
	return (result);
}

char	*call_fptr_with_length(char c, char l, long long *data)
{
	//printf("int c = %c\n", c);
	//printf("int l = %c\n", l);
	conv_funct_ptr();
	if (l == 'H')
		*data = (char)*data;
	else if (l == 'h')
		*data = (short)*data;
	else if (l == 'l')
		*data = (long)*data;
	else if (l == 'X')
		return ((*fptr[(int)c]) (*data > 0 ? *data : *data * -1));
	else if (l == 'j')
		*data = (intmax_t)*data;
	else if (l == 'z')
		*data = (size_t)*data;
	else
		*data = (int)*data;
	return ((*fptr[(int)c]) (*data > 0 ? *data : *data * -1));
}

void	conv_funct_ptr(void)
{
	ft_bzero(fptr, 127);
	fptr['i'] = ft_lltoa;
	fptr['d'] = ft_lltoa;
}

char	*int_precision(char *str, t_flag *flags)
{
	int		len;
	int		fill;
	char	*result;
	int		num;

	num = 0;
	len = ft_strlen(str);
	fill = 0;
	result = str;
	while (flags)
	{
		if (flags->flag == '.')
		{
			num = flags->num;
			fill = num - len;
			if (fill > 0)
			{
				if (!(result = (char*)malloc(len + fill + 1)))
					return (NULL);
				fill_before(str, &result, fill, '0');
				break ;
			}
		}
		flags = flags->next;
	}
	return (result);
}

//do min_field_wid is considered last
// '+' flag overides ' '
//the '0' flag is ignored when '-' flag is present
//do alternate flag '#'
//'#' flag with '+' or ' ' flag results in undefined behavior
// 'x' conv and 'o' conv are treated as unsigned int and converted
// precision for ints: goes before min_feild_wid, adds the amount given after '.'in zeros before the number, but after the sign
// if the precision is lower than the len of int, it is ignored
// precision is done before sign and space flag?, includes negatives
// precision for chars/string is different
//make sure to account for l , ll, h, hh,  j and z. error out if not right before conv
char 	*negative_int(char *str, long long data)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = str;
	if (data < 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[i] = '-';
		while (*str)
		{
			i++;
			result[i] = *str;
			str++;
		}
		result[++i] = '\0';
	}
	return (result);
}

char	*plus_flag(char *str, long long data)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = str;
	if (data > 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[i] = '+';
		while (*str)
		{
			i++;
			result[i] = *str;
			str++;
		}
		result[++i] = '\0';
	}
	return (result);
}

char	*space_flag(char *str, long long data)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = str;
	if (data > 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[i] = ' ';
		while (*str)
		{
			i++;
			result[i] = *str;
			str++;
		}
		result[++i] = '\0';
	}
	return (result);
}

int		check_if_flag(t_flag *flags, char match)
{
	while (flags)
	{
		if (flags->flag == match)
			return (1);
		flags = flags->next;
	}
	return (0);
}

void	fill_after(char *str, char **result, int fill)
{
	int i;

	i = 0;
	while (*str)
	{
		(*result)[i] = *str;
		str++;
		i++;
	}
	while (fill)
	{
		(*result)[i] = ' ';
		i++;
		fill--;
	}
	(*result)[i] = '\0';
}

void	fill_before(char *str, char **result, int fill, char character)
{
	int i;

	i = 0;
	//account for 0x prefix?
	while ((*str < '0' || *str > '9') && character == '0')//won't for hex
	{
		(*result)[i] = *str;
		i++;
		str++;
	}
	while (fill)
	{
		(*result)[i] = character;
		i++;
		fill--;
	}
	while (*str)
	{
		(*result)[i] = *str;
		str++;
		i++;
	}
	(*result)[i] = '\0';
}

char	*min_field_wid(char *str, t_flag *flags, int num)
{
	int		len;
	int		fill;
	char	*result;
	char	character;

	result = str;
	len = ft_strlen(str);
	fill = num - len;
	character = ' ';
	if (fill > 0)
	{
		if (!(result = (char*)malloc(len + fill + 1)))
			return (NULL);
		if (check_if_flag(flags, '-') == 1)
			fill_after(str, &result, fill);
		else
		{
			if (check_if_flag(flags, '0') == 1 && check_if_flag(flags, '.') == 0)
				character = '0';
			fill_before(str, &result, fill, character);
		}
	}
	return (result);
}
