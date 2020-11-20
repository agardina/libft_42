/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:05:39 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:05:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_pop(t_stack **stack, void (*del)(void *, size_t))
{
	t_stack	*new_top;

	if (!stack || !*stack)
		return ;
	new_top = (*stack)->next;
	if (del)
		ft_lstdelone(stack, del);
	*stack = new_top;
}
