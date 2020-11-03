/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:13:59 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 22:14:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_prototypes.h"

static unsigned int	index_of_max(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	index;
	int				max;

	i = 1;
	index = 0;
	max = tab[0];
	while (i < size)
	{
		if (max < tab[i])
		{
			max = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void				selection_sort(int *tab, unsigned int size)
{
	int	last_index;

	if (!tab || !size)
		return ;
	last_index = (int)size - 1;
	while (!is_int_tab_sorted(tab, size) && 0 <= last_index)
	{
		ft_swap(&tab[last_index],
			&tab[index_of_max(tab, (unsigned int)last_index)]);
		last_index--;
	}
}
