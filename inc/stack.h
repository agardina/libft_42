/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:07:41 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:07:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H
# include "list.h"

typedef t_list	t_stack;

void			stack_destroy(t_stack **stack, void (*del)(void *, size_t));
void			*stack_peek(t_stack *stack);
void			stack_pop(t_stack **stack, void (*del)(void *, size_t));
int				stack_push(t_stack **stack, const void *content);
unsigned int	stack_size(t_stack *stack);

#endif
