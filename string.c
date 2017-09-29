/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:15:26 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/29 10:43:03 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*string_conv(t_format *format, char *str)
{
	char	*result;

	if (str == NULL)
		str = ft_strdup("(null)");
	result = str;
	if (format->precision)
		result = str_precision(result, format->precision);
	if (format->mfw)
		result = mfw_char(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

char	*str_precision(char *str, int precision)
{
	char	*result;
	int		len;

	result = str;
	len = ft_strlen(str);
	if (len > precision)
	{
		result = ft_strsub(str, 0, precision);
	}
	return (result);
}

void	str_fill_before(char *str, char **result, int fill)
{
	int i;

	i = 0;
	while (fill)
	{
		(*result)[i] = ' ';
		i++;
		fill--;
	}
	ft_strcpy((*result) + i, str);
}

char	*mfw_char(char *str, t_format *format)
{
	char	*result;
	int		len;
	int		fill;

	result = str;
	len = ft_strlen(str);
	fill = format->mfw - len;
	if (fill > 0)
	{
		if (!(result = (char*)malloc(len + fill + 1)))
			return (NULL);
		if (format->minus)
			fill_after(str, &result, fill);
		else
			str_fill_before(str, &result, fill);
		if (format->precision && len > format->precision)
			free(str);
	}
	return (result);
}
