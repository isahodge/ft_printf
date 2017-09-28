/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:16:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/27 15:04:45 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dispatcher(t_format *format, long long data)
{
	char	*result;

	result = NULL;
	result = fptr_with_length(format->conv, format->length, &data);
	//printf("format->mfw = %i\n", format->mfw);
	//printf("format->precision = %i\n", format->precision);
	if (format->precision)
		result = int_precision(result, format->precision);
	if (data < 0)
		result = negative_int(result, data);
	if (format->plus)
		result = plus_flag(result, data);
	if (format->space  && !format->plus)
		result = space_flag(result, data);
	if (format->zero || format->mfw)
		result = min_field_wid(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

char	*u_dispatcher(t_format *format, unsigned long data)
{
	char	*result;

	result = NULL;
	result = ufptr_with_length(format, &data);
	//printf("format->mfw = %i\n", format->mfw);
	if (format->precision)
		result = int_precision(result, format->precision);
	if (format->alternate)
		result = alt_flag(result, data, format);
	//if (format->plus)
	//	result = plus_flag(result, 1);
	//if (format->space  && !format->plus)
	//	result = space_flag(result, 1);
	if (format->zero || format->mfw)
		result = min_field_wid(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

char	*fptr_with_length(char c, char l, long long *data)
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

char	*ufptr_with_length(t_format *format, unsigned long *data)
{
	//printf("int c = %c\n", c);
	//printf("int l = %c\n", l);
	conv_funct_ptr();
	union data_union du;

	du.ulong = *data;
	if (format->length == 'H')
		*data = (unsigned char)*data;
	else if (format->length == 'h')
		*data = (unsigned short)*data;
	else if (format->length == 'l')
		*data = (unsigned long)*data;
	else if (format->length == 'X')
		return ((*ufptr[(int)format->conv]) (du, format, 0));
	else if (format->length == 'j')
		*data = (uintmax_t)*data;
	else if (format->length == 'z')
		*data = (size_t)*data;
	else
		*data = (unsigned int)*data;
	return ((*ufptr[(int)format->conv]) (du, format, 0));
}

void	conv_funct_ptr(void)
{
	ft_bzero(fptr, 127);
	ft_bzero(ufptr, 127);
	fptr['i'] = ft_lltoa;
	fptr['d'] = ft_lltoa;
	ufptr['u'] = ft_ultoa_base;
	ufptr['o'] = ft_ultoa_base;
	ufptr['x'] = ft_ultoa_base;
	ufptr['X'] = ft_ultoa_base;
}

char	*int_precision(char *str, int precision)
{
	int		len;
	int		fill;
	char	*result;

	len = ft_strlen(str);
	result = str;
	fill = precision - len;
	if (fill > 0)
	{
		if (!(result = (char*)ft_memalloc(len + fill + 1)))
			return (NULL);
		fill_before(str, &result, fill, '0');
	}
	return (result);
}

//do min_field_wid is considered last
// '+' flag overides ' '
//the '0' flag is ignored when '-' flag is present
//'#' flag with '+' or ' ' flag results in undefined behavior
// 'x' conv and 'o' conv are treated as unsigned int and converted
// precision for ints: goes before min_feild_wid, adds the amount given after '.'in zeros before the number, but after the sign
// if the precision is lower than the len of int, it is ignored
// precision is done before sign and space flag, includes negatives
// precision for chars/string is different
// plus flag does not work for unsigned conversions
// alternate flag adds 0, 0x, or 0X for values other than 0
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
		//free(str);
	}
	return (result);
}

char	*alt_flag(char *str, long long data, t_format *format)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	//printf("strlen = %i\n", len);
	result = str;
	if (data > 0 && (!(format->conv == 'o') && !format->precision))
	{
		//printf("1\n");
		if (format->conv == 'x' || format->conv == 'X')
		{
			if (!(result = (char*)ft_memalloc(len + 3)))
				return (NULL);
			result[0] = '0';
			if (format->conv == 'x')
				result[1] = 'x';
			else if (format->conv == 'X')
				result[1] = 'X';
			i = 2;
		}
		else
		{
			//printf("2\n");
			if (!(result = (char*)ft_memalloc(len + 2)))
				return (NULL);
			result[i++] = '0';
		}
		while (*str)//use ft_strcpy?
		{
			result[i++] = *str;
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
		//free(str);
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
		//free(str);
	}
	return (result);
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
	if ((*str == '+' || *str == '-' || *str == ' ') && character == '0')
	{
		(*result)[i++] = *str;
		str++;
	}
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1)  == 'X') 
			&& character == '0')
	{
		(*result)[i++] = *str;
		(*result)[i++] = *(str + 1);
		str += 2;
	}
	while (fill)
	{
		(*result)[i] = character;
		i++;
		fill--;
	}
	while (*str)//ft_strcpy?
	{
		(*result)[i] = *str;
		str++;
		i++;
	}
	(*result)[i] = '\0';
}

char	*min_field_wid(char *str, t_format *format)
{
	int		len;
	int		fill;
	char	*result;
	char	character;

	result = str;
	len = ft_strlen(str);
	fill = format->mfw - len;
	character = ' ';
	if (fill > 0)
	{
		if (!(result = (char*)malloc(len + fill + 1)))
			return (NULL);
		if (format->minus)
			fill_after(str, &result, fill);
		else
		{
			if (format->zero && !format->precision)
				character = '0';
			fill_before(str, &result, fill, character);
		}
		free(str);
	}
	return (result);
}
