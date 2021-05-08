/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:05:42 by agardina          #+#    #+#             */
/*   Updated: 2020/11/20 12:05:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack **stack, const void *content)
{
	t_stack	*new;

	new = ft_lstnew(content, sizeof(*content));
	if (!new)
		return (-1);
	ft_lstadd(stack, ft_lstnew(content, sizeof(*content)));
	return (0);
}
