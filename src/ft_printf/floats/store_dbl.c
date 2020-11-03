/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:19:34 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:20:30 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	store_big_dbl(t_dbl dbl, t_bigint *big)
{
	t_bigint	unit;
	int			i;

	init_bigint(big);
	create_unit(&unit, sizeof(dbl.bits.f), dbl.expo);
	i = -1;
	while (++i < dbl.expo)
		mult_bigint_by_2(&unit);
	i = 52;
	while (i > 0)
	{
		if (i < 52)
			mult_bigint_by_2(&unit);
		if (dbl.mant >> (64 - i) & 0x1)
			add_bigints(big, &unit);
		i--;
	}
	mult_bigint_by_2(&unit);
	add_bigints(big, &unit);
}

void	store_small_dbl(t_dbl dbl, t_bigint *big)
{
	t_bigint	unit;
	int			i;

	init_bigint(big);
	create_unit(&unit, sizeof(dbl.bits.f), dbl.expo);
	i = -1;
	while (--i >= dbl.expo)
		div_bigint_by_2(&unit);
	add_bigints(big, &unit);
	i = 1;
	while (i < 53)
	{
		div_bigint_by_2(&unit);
		if (dbl.mant >> (64 - i) & 0x1)
			add_bigints(big, &unit);
		i++;
	}
}
