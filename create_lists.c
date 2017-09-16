/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:51:16 by ihodge            #+#    #+#             */
/*   Updated: 2017/09/13 19:06:37 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag		*create_flag(void)
{
	t_flag	*new;

	if (!(new = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	new->num = 0;
	new->flag = 0;
	new->next = NULL;
	return (new);
}

t_format	*create_format(void)
{
	t_format	*new;

	if (!(new = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	new->result = NULL;
	new->conv = 0;
	new->flag = create_flag();
	new->next = NULL;
	return (new);
}
