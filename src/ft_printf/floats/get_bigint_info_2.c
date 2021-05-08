/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bigint_info_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:43:17 by agardina          #+#    #+#             */
/*   Updated: 2021/05/09 13:43:25 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	get_next_figure(t_bigint *big)
{
	int				index_case;
	int				index_fig;
	unsigned int	nb;
	int				i;

	if (big->last_digit_rank == 0)
		index_case = big->last_dec_case + 1;
	else
		index_case = big->last_dec_case;
	index_fig = big->last_digit_rank + 1;
	nb = (big->tab)[index_case];
	i = 0;
	while (i < 9 - index_fig)
	{
		nb /= 10;
		i++;
	}
	return (nb % 10);
}

int	get_last_digit_rank(int16_t expo, int prec, t_bigint *big)
{
	int	res;

	if (expo >= 0 && !big->is_long)
	{
		if (prec <= 6)
			res = (prec + 3) % 9;
		else
			res = (prec - 6) % 9;
	}
	else
		res = prec % 9;
	return (res);
}

int	get_first_int_case(int16_t expo, t_bigint *big)
{
	int	i;

	i = 0;
	if (expo < 0)
		big->first_int_case = 0;
	else
	{
		while ((big->tab)[i] == 0)
			i++;
		big->first_int_case = i;
	}
	return (0);
}

void	get_bigint_info(t_bigint *big, int16_t expo, int prec)
{
	get_first_int_case(expo, big);
	if (expo < 0)
		big->last_int_case = 0;
	else
	{
		if (big->is_long)
			big->last_int_case = BIGINT_SIZE - 8;
		else
			big->last_int_case = BIGINT_SIZE - 7;
	}
	if (expo >= 0)
		big->first_dec_case = BIGINT_SIZE - 7;
	else
		big->first_dec_case = 1;
	big->last_dec_case = get_last_dec_case(expo, prec, big);
	big->last_digit_rank = get_last_digit_rank(expo, prec, big);
	big->next_figure = get_next_figure(big);
}
