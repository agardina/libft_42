/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:05:35 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:05:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*stack_peek(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->content);
}
