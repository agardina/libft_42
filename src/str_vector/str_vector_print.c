/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vector_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:59:12 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 15:59:13 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_vector_print(t_str_vector *vect)
{
	unsigned int	i;

	if (!vect || !vect->tab)
		return ;
	i = 0;
	while (i < vect->used_size)
		ft_printf("%s\n", vect->tab[i++]);
}
