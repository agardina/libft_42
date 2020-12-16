/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:35 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:42:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			int_vector_append(t_int_vector *vect, int nb)
{
	if (!vect)
		return (1);
	if (vect->length == vect->total_size)
	{
		int_vector_realloc(vect);
		if (!vect->tab)
			return (1);
	}
	vect->tab[vect->length] = nb;
	vect->length++;
	return (0);
}
