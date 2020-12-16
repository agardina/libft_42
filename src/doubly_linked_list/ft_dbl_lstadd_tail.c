/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:35 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:23:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstadd_tail(t_dbl_list *list, t_dbl_list_elt *new)
{
	if (!list || !new)
		return ;
	if (!list->size)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	list->size++;
}
