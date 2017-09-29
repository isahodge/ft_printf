/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:12:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/29 10:58:57 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*negative_int(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = str;
	if (data < 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '-';
		ft_strcpy(result + 1, str);
	}
	return (result);
}

char	*alt_flag(char *str, t_format *format)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = str;
	if (format->conv == 'x' || format->conv == 'X' || format->conv == 'p')
	{
		if (!(result = (char*)ft_memalloc(len + 3)))
			return (NULL);
		result[0] = '0';
		if (format->conv == 'x' || format->conv == 'p')
			result[1] = 'x';
		else if (format->conv == 'X')
			result[1] = 'X';
		ft_strcpy(result + 2, str);
	}
	else if (!format->precision)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '0';
		ft_strcpy(result + 1, str);
	}
	return (result);
}

char	*plus_flag(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = str;
	if (data > 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '+';
		ft_strcpy(result + 1, str);
	}
	return (result);
}

char	*space_flag(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = str;
	if (data > 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = ' ';
		ft_strcpy(result + 1, str);
	}
	return (result);
}
