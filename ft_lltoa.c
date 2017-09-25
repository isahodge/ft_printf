/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:00:37 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/23 17:51:51 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

static int	ft_intlen(long long n, int int_len)
{
	if (n < 0)
	{
		n *= -1;
		int_len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len);
}

char		*ft_lltoa(long long n)
{
	char	*fresh;
	int		int_len;
	int		i;

	i = 0;
	int_len = ft_intlen(n, 1);
	fresh = ft_strnew(int_len);
	if (fresh == NULL)
		return (NULL);
	fresh[int_len - 1] = n < 0 ? '-' : '0';
	if (n < 0)
		n = -n;
	while (i < int_len && n > 0)
	{
		fresh[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	ft_reverse(fresh);
	return (fresh);
}
