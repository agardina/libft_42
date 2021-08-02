/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vector_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:59:05 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 15:59:07 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str_vector	*str_vector_create(void)
{
	t_str_vector	*new;

	new = (t_str_vector *)ft_memalloc(sizeof(t_str_vector));
	if (!new)
		return (NULL);
	new->tab = (char **)ft_memalloc(sizeof(char *) * STR_VECTOR_INIT_SIZE);
	if (!new->tab)
	{
		free(new);
		return (NULL);
	}
	new->total_size = STR_VECTOR_INIT_SIZE;
	new->used_size = 0;
	return (new);
}
