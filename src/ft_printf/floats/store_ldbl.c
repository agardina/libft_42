/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_ldbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:20:43 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:21:58 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	store_big_ldbl(t_ldbl ldbl, t_bigint *big)
{
	t_bigint	unit;
	int			i;
	int			j;

	init_bigint(big);
	create_unit(&unit, sizeof(ldbl.bits.f), ldbl.expo);
	i = -1;
	while (++i < ldbl.expo)
		mult_bigint_by_2(&unit);
	i = -1;
	j = 15;
	while (++i < 4)
	{
		while (j >= 0)
		{
			if (!(i == 0 && j == 15))
				mult_bigint_by_2(&unit);
			if (ldbl.bits.u[i] >> (15 - j) & 0x1)
				add_bigints(big, &unit);
			j--;
		}
		j = 15;
	}
}

void	store_small_ldbl(t_ldbl ldbl, t_bigint *big)
{
	t_bigint	unit;
	int			i;
	int			j;

	init_bigint(big);
	create_unit(&unit, sizeof(ldbl.bits.f), ldbl.expo);
	i = -1;
	while (--i >= ldbl.expo)
		div_bigint_by_2(&unit);
	i = 3;
	j = 0;
	while (i >= 0)
	{
		while (j <= 15)
		{
			if (ldbl.bits.u[i] >> (15 - j) & 0x1)
				add_bigints(big, &unit);
			div_bigint_by_2(&unit);
			j++;
		}
		j = 0;
		i--;
	}
}
