/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:43:13 by agardina          #+#    #+#             */
/*   Updated: 2020/11/05 13:43:14 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bubble_sort(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int index_sorted;

	if (!tab || size < 2)
		return ;
	index_sorted = size;
	while (!is_int_tab_sorted(tab, size))
	{
		i = 0;
		j = 1;
		while (j < index_sorted)
		{
			if (tab[j] < tab[i])
				ft_swap(&tab[j], &tab[i]);
			i++;
			j++;
		}
		index_sorted--;
	}
}
