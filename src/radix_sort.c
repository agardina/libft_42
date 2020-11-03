/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:57:45 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 16:57:57 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void			counting_sort(int *tab, int *new_tab, int div,
						unsigned int size)
{
	int	count_tab[10];
	int	i;
	int count_index;
	int new_tab_index;

	i = -1;
	while (++i < 10)
		count_tab[i] = 0;
	i = 0;
	while (i < (int)size)
		count_tab[(tab[i++] / div) % 10]++;
	i = 0;
	while (++i < 10)
		count_tab[i] += count_tab[i - 1];
	i = size;
	while (0 <= --i)
	{
		count_index = (tab[i] / div) % 10;
		new_tab_index = count_tab[count_index] - 1;
		count_tab[count_index]--;
		new_tab[new_tab_index] = tab[i];
	}
	i = -1;
	while (++i < (int)size)
		tab[i] = new_tab[i];
}

static unsigned int	get_loop_nb(int *tab, unsigned int size)
{
	int				max;
	int				loop_nb;
	unsigned int	i;

	max = tab[0];
	loop_nb = 1;
	i = 1;
	while (i < size)
	{
		max = max < tab[i] ? tab[i] : max;
		i++;
	}
	while (10 <= max)
	{
		max /= 10;
		loop_nb++;
	}
	return (loop_nb);
}

char				radix_sort(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	div;
	unsigned int	loop_nb;
	int				*new_tab;

	div = 1;
	loop_nb = get_loop_nb(tab, size);
	if (!(new_tab = (int*)malloc(sizeof(int) * size)))
		return (1);
	while (1 <= loop_nb)
	{
		i = 0;
		while (i < size)
			new_tab[i++] = 0;
		counting_sort(tab, new_tab, div, size);
		div *= 10;
		loop_nb--;
	}
	free(new_tab);
	return (0);
}
