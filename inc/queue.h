/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:07:47 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:07:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H

# define QUEUE_H
# include "list.h"

typedef t_list	t_queue;

void			queue_dequeue(t_queue **queue, void (*del)(void *, size_t));
void			queue_destroy(t_queue **queue, void (*del)(void *, size_t));
int				queue_enqueue(t_queue **queue, const void *content);
void			*queue_peek(t_queue *queue);
unsigned int	queue_size(t_queue *queue);

#endif
