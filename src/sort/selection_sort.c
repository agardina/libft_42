/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:48 by agardina          #+#    #+#             */
/*   Updated: 2020/12/14 17:00:52 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	selection_sort(int *tab, unsigned int size)
{
	unsigned int	unsorted;
	unsigned int	i;
	int				index_of_min;

	if (!tab || size <= 1)
		return ;
	unsorted = 0;
	while (unsorted < size - 1)
	{
		i = unsorted + 1;
		index_of_min = unsorted;
		while (i < size)
		{
			if (tab[i] < tab[index_of_min])
				index_of_min = i;
			i++;
		}
		ft_swap(&tab[unsorted], &tab[index_of_min]);
		unsorted++;
	}
	return ;
}
