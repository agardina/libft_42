/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:47:27 by agardina          #+#    #+#             */
/*   Updated: 2020/11/04 17:47:29 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	quicksort(int *tab, int imin, int imax)
{
	int	pivot;
	int	i;
	int	j;

	if (!tab || imin < 0 || imax < 0 || imax <= imin
		|| is_int_tab_sorted(tab + imin, imax - imin + 1))
		return ;
	pivot = tab[imax];
	i = imin;
	j = imax - 1;
	while (i <= j)
	{
		while (i < imax && tab[i] <= pivot)
			i++;
		while (imin <= j && pivot <= tab[j])
			j--;
		if (i < j)
			ft_swap(&tab[i], &tab[j]);
	}
	ft_swap(&tab[i], &tab[imax]);
	quicksort(tab, imin, i - 1);
	quicksort(tab, i + 1, imax);
}
