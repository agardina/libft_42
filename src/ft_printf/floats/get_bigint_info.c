/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bigint_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:58:52 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 13:14:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

static	int	get_last_dec_case_no_precision(int16_t expo,
	t_bigint *big, int first_case)
{
	if (expo >= 0 && !big->is_long)
		return (first_case);
	return (first_case - 1);
}

int	get_last_dec_case(int16_t expo, int prec, t_bigint *big)
{
	int	first_case;
	int	res;

	first_case = big->first_dec_case;
	if (!prec)
		return (get_last_dec_case_no_precision(expo, big, first_case));
	if (expo >= 0 && !big->is_long)
	{
		res = first_case;
		if ((prec - 6) > 0)
			res += (prec - 6) / 9;
		if (((prec - 6) % 9) > 0)
			res += 1;
	}
	else
	{
		res = prec / 9;
		if (prec % 9)
			res += 1;
		if (big->is_long && expo >= 0)
			res += BIGINT_SIZE - 8;
	}
	if (res < BIGINT_SIZE)
		return (res);
	return (BIGINT_SIZE - 1);
}
