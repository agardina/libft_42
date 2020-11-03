/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:04:27 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 20:05:57 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void			mult_bigint_by_2(t_bigint *big)
{
	unsigned int	surplus;
	int				i;

	i = BIGINT_SIZE - 1;
	surplus = 0;
	while (i >= 0)
	{
		(big->tab)[i] *= 2;
		(big->tab)[i] += surplus / (CELL_LIMIT + 1);
		if ((big->tab)[i] > CELL_LIMIT)
		{
			surplus = CELL_LIMIT + 1;
			(big->tab)[i] -= CELL_LIMIT + 1;
		}
		else
			surplus = 0;
		i--;
	}
}

void			div_bigint_by_2(t_bigint *big)
{
	int				i;
	unsigned int	mod;
	unsigned int	res;

	i = 0;
	mod = 0;
	while ((big->tab)[i] == 0)
		i++;
	while (i < BIGINT_SIZE)
	{
		res = ((big->tab)[i] / 2) + mod;
		mod = (big->tab)[i] % 2 == 1 ? 500000000 : 0;
		(big->tab)[i] = res;
		i++;
	}
}

unsigned int	div_by_10(unsigned int nb, int power)
{
	int	i;

	i = 0;
	if (power > 0)
	{
		while (i < power)
		{
			nb /= 10;
			i++;
		}
	}
	return (nb);
}

void			add_bigints(t_bigint *big, t_bigint *to_add)
{
	unsigned int	surplus;
	int				i;

	i = BIGINT_SIZE - 1;
	surplus = 0;
	while (i >= 0)
	{
		(big->tab)[i] += (to_add->tab)[i];
		(big->tab)[i] += surplus / (CELL_LIMIT + 1);
		if ((big->tab)[i] > CELL_LIMIT)
		{
			surplus = CELL_LIMIT + 1;
			(big->tab)[i] -= CELL_LIMIT + 1;
		}
		else
			surplus = 0;
		i--;
	}
}
