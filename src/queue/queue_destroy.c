/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:40 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:04:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_destroy(t_queue **queue, void (*del)(void *, size_t))
{
	if (queue && *queue)
		ft_lstdel(queue, del);
}
