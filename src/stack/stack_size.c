/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:05:47 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:05:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

unsigned int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (ft_lstsize(stack));
}
