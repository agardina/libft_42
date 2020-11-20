/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:36 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:04:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_dequeue(t_queue **queue, void (*del)(void *, size_t))
{
	t_queue	*new_head;

	if (!queue || !*queue)
		return ;
	new_head = (*queue)->next;
	if (del)
		ft_lstdelone(queue, del);
	*queue = new_head;
}
