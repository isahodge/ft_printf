/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:42:37 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/26 12:32:51 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

void	set_var(t_format *format, union data_union du, unsigned int *base,
		unsigned long *val)
{
	if (format->conv == 'x' || format->conv == 'X')
		*base = 16;
	else if (format->conv == 'o')
		*base = 8;
	else
		*base = 10;
	if (format->length == 'H')
		*val = du.uchar;
	else if (format->length == 'h')
		*val = du.ushort;
	else if (format->length == 'l')
		*val = du.ulong;
	else if (format->length == 'X')
		*val = du.ulong;
	else if (format->length == 'j')
		*val = du.uintmaxt;
	else if (format->length == 'z')
		*val = du.usizet;
	else
		*val = du.uint;
}

char	*ft_ultoa_base(union data_union du, t_format *format, unsigned int base)
{
	int				i;
	char			*str;
	unsigned long	tmp;
	int				character;
	unsigned long	val;

	set_var(format, du, &base, &val);
	character = 'a';
	if (format->conv == 'X')
		character = 'A';
	i = 1;
	tmp = val;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char*)ft_memalloc((i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- >= 0)
	{
		tmp = val % base;
		str[i] = tmp >= 10 ? tmp - 10 + character : tmp + '0';
		val = val / base;
	}
	return (str);
}

/*int		main(void)
{
	int i;
	union data_union du;
	t_format *format;

	format = create_format();
	format->conv = 'X';
	format->length = 'l';
	i = -50;
	du.ulong = i;
	printf("%s\n", ft_ultoa_base(du, format, 0));
	printf("%lX\n", (unsigned long)i);
	return (0);
}*/
