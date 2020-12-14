/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:10 by agardina          #+#    #+#             */
/*   Updated: 2020/12/14 17:00:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bubble_sort(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	if (!tab || size <= 1)
		return ;
	i = size - 1;
	while (0 < i)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j + 1] < tab[j])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i--;
	}
	return ;
}
