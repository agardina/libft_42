/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:47 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 16:35:48 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_vector	*int_vector_create(void)
{
	t_int_vector	*new;

	new = (t_int_vector*)ft_memalloc(sizeof(t_int_vector));
	if (!new)
		return (NULL);
	new->tab = (int*)ft_memalloc(sizeof(int) * INT_VECTOR_INIT_SIZE);
	if (!new->tab)
		return (NULL);
	new->total_size = INT_VECTOR_INIT_SIZE;
	new->length = 0;
	return (new);
}
