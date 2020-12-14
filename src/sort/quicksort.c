/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:36 by agardina          #+#    #+#             */
/*   Updated: 2020/12/14 17:00:40 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	partition(int *tab, int start, int end)
{
	int	pivot;
	int	l;
	int	r;

	if (end <= start)
		return ;
	pivot = tab[end];
	l = start;
	r = end - 1;
	while (l < r)
	{
		while (tab[l] < pivot)
			l++;
		while (start < r && pivot <= tab[r])
			r--;
		if (l < r)
			ft_swap(&tab[l], &tab[r]);
	}
	if (pivot < tab[l])
		ft_swap(&tab[l], &tab[end]);
	partition(tab, start, l - 1);
	partition(tab, l + 1, end);
}

void		quicksort(int *tab, unsigned int size)
{
	if (!tab || size <= 1)
		return ;
	partition(tab, 0, size - 1);
	return ;
}
