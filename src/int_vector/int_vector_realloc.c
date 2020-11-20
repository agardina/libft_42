/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:54 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 16:35:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_vector	*int_vector_realloc(t_int_vector *old)
{
	t_int_vector	*new;

	if (!old)
		return (NULL);
	if (!(new = (t_int_vector*)ft_memalloc(sizeof(t_int_vector))))
		return (NULL);
	if (!(new->tab = (int*)ft_memalloc(sizeof(int) * old->total_size * 2)))
	{
		free(new);
		new = NULL;
		free(old->tab);
		old->tab = NULL;
		free(old);
		old = NULL;
	}
	new->total_size = old->total_size * 2;
	new->length = old->length;
	if (old->tab)
		ft_memcpy(new->tab, old->tab, sizeof(int) * old->total_size);
	int_vector_destroy(&old);
	return (new);
}
