/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:40 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:38:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstdel(t_dbl_list *list)
{
	t_dbl_list_elt	*next;

	if (!list)
		return ;
	while (list->head)
	{
		next = list->head->next;
		if (list->del)
			list->del(list->head->content, list->head->content_size);
		free(list->head);
		list->head = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
