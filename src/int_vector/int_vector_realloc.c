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

void	int_vector_realloc(t_int_vector *vect)
{
	int	*new;

	if (!vect)
		return ;
	new = (int *)ft_memalloc(sizeof(int) * vect->total_size * 2);
	if (!new)
	{
		free(vect->tab);
		vect->tab = NULL;
		free(vect);
		vect = NULL;
		return ;
	}
	if (vect->tab)
	{
		ft_memcpy(new, vect->tab, sizeof(int) * vect->total_size);
		free(vect->tab);
	}
	vect->tab = new;
	vect->total_size = vect->total_size * 2;
}
