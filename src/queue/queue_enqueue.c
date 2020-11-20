/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_enqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:45 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:04:46 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	queue_enqueue(t_queue **queue, const void *content)
{
	t_queue	*new;

	if (!(new = ft_lstnew(content, sizeof(*content))))
		return (-1);
	ft_lstadd_tail(queue, new);
	return (0);
}
