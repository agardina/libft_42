/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:06:21 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 17:06:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_vector_print(t_int_vector *vect)
{
	unsigned int	i;

	if (!vect || !vect->tab)
		return ;
	i = 0;
	while (i < vect->length)
		ft_printf("%d\n", vect->tab[i++]);
}
