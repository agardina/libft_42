/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:54 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:44:40 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dbl_lstdelhead(t_dbl_list *list)
{
	t_dbl_list_elt	*to_del;

	if (!list)
		return ;
	to_del = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	if (list->del)
		list->del(to_del->content, to_del->content_size);
	free(to_del);
	list->size--;
}

static void	ft_dbl_lstdeltail(t_dbl_list *list)
{
	t_dbl_list_elt	*to_del;

	if (!list)
		return ;
	to_del = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	if (list->del)
		list->del(to_del->content, to_del->content_size);
	free(to_del);
	list->size--;
}

void		ft_dbl_lstdelone(t_dbl_list *list, t_dbl_list_elt *e)
{
	t_dbl_list_elt	*prev;
	t_dbl_list_elt	*next;

	if (!list || !e)
		return ;
	prev = e->prev;
	next = e->next;
	if (!prev)
		return (ft_dbl_lstdelhead(list));
	if (!next)
		return (ft_dbl_lstdeltail(list));
	prev->next = next;
	next->prev = prev;
	if (list->del)
		list->del(e->content, e->content_size);
	free(e);
	list->size--;
}
