/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_vector_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:51:16 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 18:51:17 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	is_int_vector_sorted(t_int_vector *vect)
{
	if (!vect)
		return (0);
	if (vect->length == 1)
		return (1);
	return (is_int_tab_sorted(vect->tab, vect->length));
}
