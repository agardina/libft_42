/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:09:24 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 18:09:25 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_vector_destroy(t_int_vector **vect)
{
	if (!vect || !*vect)
		return ;
	free((*vect)->tab);
	(*vect)->tab = NULL;
	free(*vect);
	*vect = NULL;
}
