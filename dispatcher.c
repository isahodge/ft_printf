/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:16:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/29 11:08:20 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dispatcher(t_format *format, long long data)
{
	char	*result;

	result = NULL;
	if (format->conv == 'D')
	{
		format->conv = 'd';
		format->length = 'l';
	}
	result = fptr_with_length(format->conv, format->length, &data);
	if (format->precision)
		result = int_precision(result, format->precision);
	if (data < 0)
		result = negative_int(result, data);
	if (format->plus)
		result = plus_flag(result, data);
	if (format->space && !format->plus)
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
	if (format->conv == 'p')
	{
		format->alternate = 1;
		format->length = 'l';
	}
	result = ufptr_with_length(format, &data);
	if (format->precision)
		result = int_precision(result, format->precision);
	if (format->alternate && (data > 0 || format->conv == 'p'))
		result = alt_flag(result, format);
	if (format->zero || format->mfw)
		result = min_field_wid(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

char	*fptr_with_length(char c, char l, long long *data)
{
	conv_funct_ptr();
	if (l == 'H')
		*data = (char)*data;
	else if (l == 'h')
		*data = (short)*data;
	else if (l == 'l')
		*data = (long)*data;
	else if (l == 'X')
		return ((*fptr[(int)c])(*data > 0 ? *data : *data * -1));
	else if (l == 'j')
		*data = (intmax_t)*data;
	else if (l == 'z')
		*data = (size_t)*data;
	else
		*data = (int)*data;
	return ((*fptr[(int)c])(*data > 0 ? *data : *data * -1));
}

char	*ufptr_with_length(t_format *format, unsigned long *data)
{
	union u_data_union du;

	conv_funct_ptr();
	du.ulong = *data;
	if (format->length == 'H')
		*data = (unsigned char)*data;
	else if (format->length == 'h')
		*data = (unsigned short)*data;
	else if (format->length == 'l')
		*data = (unsigned long)*data;
	else if (format->length == 'X')
		return ((*ufptr[(int)format->conv])(du, format, 0));
	else if (format->length == 'j')
		*data = (uintmax_t)*data;
	else if (format->length == 'z')
		*data = (size_t)*data;
	else
		*data = (unsigned int)*data;
	return ((*ufptr[(int)format->conv])(du, format, 0));
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
	ufptr['p'] = ft_ultoa_base;
}
