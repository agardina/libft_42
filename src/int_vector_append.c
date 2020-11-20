/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:35 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 16:35:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			int_vector_append(t_int_vector **vect, int nb)
{
	if (!vect || !*vect || !(*vect)->tab)
		return (1);
	if ((*vect)->length == (*vect)->total_size)
	{
		*vect = int_vector_realloc(*vect);
		ft_printf("OK\n");
		if (!vect)
			return (1);
	}
	(*vect)->tab[(*vect)->length] = nb;
	(*vect)->length++;
	return (0);
}
