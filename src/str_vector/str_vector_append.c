/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vector_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:59:02 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 15:59:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_vector_append(t_str_vector *vect, const char *str)
{
	if (!vect)
		return (1);
	if (vect->used_size == vect->total_size)
	{
		str_vector_realloc(vect);
		if (!vect->tab)
			return (1);
	}
	vect->tab[vect->used_size] = ft_strdup(str);
	if (!vect->tab[vect->used_size])
		return (1);
	vect->used_size++;
	return (0);
}
