/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:16:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/15 20:42:49 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dispatcher(t_format *format, int data)
{
	char	*result;
	t_flag	*flags;

	conv_funct_ptr();
	flags = format->flag;
	result = NULL;
	result = (*fptr[(int)format->conv]) (data);
	while (flags)
	{
		if (flags->flag == '+' && data > 0)
			result = plus_flag(result);
		else if (flags->flag == ' ' && data > 0 && 
				check_if_flag(format->flag, '+') == 0)
			result = space_flag(result);
		else if (flags->num > 0)
			result = min_field_wid(result, format->flag, flags->num);
		flags = flags->next;
	}
	return (result);
}

void	conv_funct_ptr(void)
{
	ft_bzero(fptr, 127);
	fptr['i'] = ft_itoa;
	fptr['d'] = ft_itoa;
}

//do min_field_wid is considered last
//plus sign flag adds sign to both pos and neg nums. signed numbers will always be printed with leading sign
// the ' ' flag precedes positive numbers with a space and negative numbers with -
// '+' flag overides ' '
//the '0' flag is ignored when '-' flag is present
//the '-' = left feild adjust
//do plus flag. check for space flag, only execute if plus flag not present.
//do alternate flag '#'
//'#' flag with '+' or ' ' flag results in undefined behavior
// 'x' conv and 'o' conv are treated as unsigned int and converted
char	*plus_flag(char *str)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char*)ft_memalloc(len + 2);
	result[i] = '+';
	while (*str)
	{
		i++;
		result[i] = *str;
		str++;
	}
	result[++i] = '\0';
	return (result);
}

char	*space_flag(char *str)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char*)ft_memalloc(len + 2);
	result[i] = ' ';
	while (*str)
	{
		i++;
		result[i] = *str;
		str++;
	}
	result[++i] = '\0';
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

//+, space, -, and # flags have to be given before the minfieldwid, else undefined behavior
//check for '-' and '0'
char	*min_field_wid(char *str, t_flag *flags, int num)
{
	int		len;
	int		fill;
	char	*result;
	int		i;
	char	character;

	i = 0;
	result = str;
	len = ft_strlen(str);
	fill = num - len;
	character = ' ';
	printf("fill = %i\n", fill);
	if (fill > 0)
	{
		if (!(result = (char*)malloc(sizeof(len + fill + 1))))
			return (NULL);
		if (check_if_flag(flags, '-') == 1)
		{
			while (*str)
			{
				result[i] = *str;
				str++;
				i++;
			}
			while (fill)
			{
				result[i] = character;
				i++;
				fill--;
			}
		}
		else
		{
			if (check_if_flag(flags, '0') == 1)
				character = '0';
			while (fill)
			{
				result[i] = character;
				i++;
				fill--;
			}
			while (*str)
			{
				result[i] = *str;
				i++;
				str++;
			}
		}
		result[i] = '\0';
	}
	return (result);
}
