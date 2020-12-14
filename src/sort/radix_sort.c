/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:00:42 by agardina          #+#    #+#             */
/*   Updated: 2020/12/14 17:00:45 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_nb_turns(int *tab, unsigned int size)
{
	unsigned int	i;
	int				max;
	int				nb_turns;

	i = 1;
	max = tab[0];
	nb_turns = 1;
	while (i < size)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	while (max / 10)
	{
		nb_turns++;
		max /= 10;
	}
	return (nb_turns);
}

static void			fill_count_tab(int *tab, unsigned int size,
						int count_tab[10], unsigned int div)
{
	unsigned int	i;
	int				res;

	ft_bzero(count_tab, sizeof(int) * 10);
	i = 0;
	while (i < size)
	{
		res = (tab[i] / div) % 10;
		count_tab[res]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count_tab[i] += count_tab[i - 1];
		i++;
	}
}

void				radix_sort(int *tab, unsigned int size)
{
	int					*aux;
	int					count_tab[10];
	unsigned int		nb_turns;
	unsigned int		div;
	int					i;

	if (!tab || size <= 1 || !(aux = (int*)malloc(sizeof(int) * size)))
		return ;
	nb_turns = get_nb_turns(tab, size);
	div = 1;
	while (nb_turns--)
	{
		fill_count_tab(tab, size, count_tab, div);
		i = size;
		while (0 <= --i)
		{
			aux[count_tab[(tab[i] / div) % 10] - 1] = tab[i];
			count_tab[(tab[i] / div) % 10]--;
		}
		ft_memcpy(tab, aux, sizeof(int) * size);
		div *= 10;
	}
	free(aux);
	return ;
}
