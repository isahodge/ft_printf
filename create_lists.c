/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:51:16 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/26 17:03:16 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	*create_format(void)
{
	t_format	*new;

	if (!(new = (t_format*)ft_memalloc(sizeof(t_format))))
		return (NULL);
	new->conv = 0;
	new->length = 0;
	new->space = 0;
	new->plus = 0;
	new->minus = 0;
	new->alternate = 0;
	new->zero = 0;
	new->mfw = 0;
	new->precision = 0;
	new->strlength = 0;
	return (new);
}
