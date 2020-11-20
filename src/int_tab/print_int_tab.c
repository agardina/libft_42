/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:08:34 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 17:10:48 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	print_int_tab(int *tab, unsigned int size)
{
	unsigned int i;

	if (!tab)
		return ;
	i = 0;
	while (i < size)
		ft_printf("%d ", tab[i++]);
	ft_printf("\n");
}
