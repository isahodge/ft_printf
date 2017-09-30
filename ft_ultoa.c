/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:05:37 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/25 15:50:32 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_reverse(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

static int	ft_intlen(unsigned long n, int int_len)
{
	while (n >= 10)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len);
}

char		*ft_ultoa(unsigned long n)
{
	char	*fresh;
	int		int_len;
	int		i;

	i = 0;
	int_len = ft_intlen(n, 1);
	fresh = ft_strnew(int_len);
	if (fresh == NULL)
		return (NULL);
	while (i < int_len && n > 0)
	{
		fresh[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	ft_reverse(fresh);
	return (fresh);
}
