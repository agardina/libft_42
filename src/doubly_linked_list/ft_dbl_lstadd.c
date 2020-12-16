/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:28 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:23:32 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstadd(t_dbl_list *list, t_dbl_list_elt *new)
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
		list->head->prev = new;
		new->next = list->head;
		list->head = new;
	}
	list->size++;
}
