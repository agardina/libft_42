/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:29 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:41:54 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_aux_to_tab(int *tab, int *aux, unsigned int start,
				unsigned int aux_len)
{
	unsigned int	i;

	i = 0;
	while (i < aux_len)
	{
		tab[start + i] = aux[i];
		i++;
	}
}

static void	merge(int *tab, unsigned int start, unsigned int end, int *aux)
{
	unsigned int	l;
	unsigned int	middle;
	unsigned int	r;
	unsigned int	i;

	middle = (start + end) / 2;
	l = start;
	r = middle + 1;
	i = 0;
	while (l <= middle || r <= end)
	{
		if (middle < l || (r <= end && tab[r] <= tab[l]))
		{
			aux[i] = tab[r];
			r++;
		}
		else if (end < r || (l <= middle && tab[l] <= tab[r]))
		{
			aux[i] = tab[l];
			l++;
		}
		i++;
	}
	copy_aux_to_tab(tab, aux, start, i);
}

static void	divide(int *tab, unsigned int start, unsigned int end, int *aux)
{
	unsigned int	middle;

	if (start == end)
		return ;
	middle = (start + end) / 2;
	divide(tab, start, middle, aux);
	divide(tab, middle + 1, end, aux);
	merge(tab, start, end, aux);
}

void		merge_sort(int *tab, unsigned int size)
{
	int	*aux;

	if (!tab || size <= 1)
		return ;
	if (!(aux = (int*)malloc(sizeof(int) * size)))
		return ;
	divide(tab, 0, size - 1, aux);
	free(aux);
	return ;
}
