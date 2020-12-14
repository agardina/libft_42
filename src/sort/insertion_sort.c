/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:21 by agardina          #+#    #+#             */
/*   Updated: 2020/12/14 17:00:26 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insertion_sort(int *tab, unsigned int size)
{
	unsigned int	unsorted;
	unsigned int	i;

	if (!tab || size <= 1)
		return ;
	unsorted = 1;
	while (unsorted < size)
	{
		i = unsorted;
		while (0 < i)
		{
			if (tab[i] < tab[i - 1])
				ft_swap(&tab[i], &tab[i - 1]);
			else
				break ;
			i--;
		}
		unsorted++;
	}
	return ;
}
