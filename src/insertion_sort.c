/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:31:40 by agardina          #+#    #+#             */
/*   Updated: 2020/11/04 01:31:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insertion_sort(int *tab, unsigned int size)
{
	unsigned int	index_to_sort;
	unsigned int	i;
	int				insert_index;

	if (!tab || size <= 1)
		return ;
	index_to_sort = 1;
	while (!is_int_tab_sorted(tab, size))
	{
		insert_index = 0;
		while (tab[insert_index] < tab[index_to_sort])
			insert_index++;
		i = index_to_sort;
		while (insert_index < (int)i)
		{
			ft_swap(&tab[i - 1], &tab[i]);
			i--;
		}
		index_to_sort++;
	}
}
