/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:48:08 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:37:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	round_up_bigint(t_bigint *big, unsigned int last_case_to_print)
{
	t_bigint		prec_to_add;
	int				index;

	if (big->next_figure > 4)
	{
		if (get_uint_len(last_case_to_print) == 9
				&& only_nine((big->tab)[big->last_dec_case]))
		{
			(big->tab)[big->last_dec_case] = 0;
			index = big->last_dec_case - 1;
		}
		else
			index = big->last_dec_case;
		get_prec_to_add(&prec_to_add, index);
		add_bigints(big, &prec_to_add);
	}
}

void	get_prec_to_add(t_bigint *to_add, int index)
{
	init_bigint(to_add);
	(to_add->tab)[index] = 1;
}

void	cut_tab(t_bigint *big)
{
	int	i;

	i = big->last_dec_case;
	(big->tab)[i] = div_by_10((big->tab)[i], big->last_digit_rank > 0 ?
			9 - big->last_digit_rank : 0);
	i++;
	while (i < BIGINT_SIZE)
	{
		(big->tab)[i] = 0;
		i++;
	}
}
