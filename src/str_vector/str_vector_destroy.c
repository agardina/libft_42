/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vector_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:59:10 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 15:59:10 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_vector_destroy(t_str_vector **vect)
{
	unsigned int	i;

	if (!vect || !*vect)
		return ;
	i = 0;
	while (i < (*vect)->used_size)
	{
		free((*vect)->tab[i]);
		i++;
	}
	free((*vect)->tab);
	(*vect)->tab = NULL;
	free(*vect);
	*vect = NULL;
}
