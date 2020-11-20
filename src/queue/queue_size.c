/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:59 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:05:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

unsigned int	queue_size(t_queue *queue)
{
	if (!queue)
		return (0);
	return (ft_lstsize(queue));
}
