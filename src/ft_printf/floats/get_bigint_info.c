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

int		get_next_figure(t_bigint *big)
{
	int				index_case;
	int				index_fig;
	unsigned int	nb;
	int				i;

	index_case = big->last_dec_case + (big->last_digit_rank == 0 ? 1 : 0);
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

int		get_last_dec_case(int16_t expo, int prec, t_bigint *big)
{
	int	first_case;
	int	res;

	first_case = big->first_dec_case;
	if (!prec)
		return ((expo >= 0 && !big->is_long) ? first_case : first_case - 1);
	if (expo >= 0 && !big->is_long)
	{
		res = first_case;
		res += (prec - 6 > 0) ? ((prec - 6) / 9) : 0;
		res += ((prec - 6) % 9) > 0 ? 1 : 0;
	}
	else
		res = (prec / 9) + (prec % 9 ? 1 : 0) +
			(big->is_long && expo >= 0 ? (BIGINT_SIZE - 8) : 0);
	return (res = res < BIGINT_SIZE ? res : (BIGINT_SIZE - 1));
}

int		get_last_digit_rank(int16_t expo, int prec, t_bigint *big)
{
	int	res;

	if (expo >= 0 && !big->is_long)
		res = (prec <= 6 ? ((prec + 3) % 9) : ((prec - 6) % 9));
	else
		res = prec % 9;
	return (res);
}

int		get_first_int_case(int16_t expo, t_bigint *big)
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
		big->last_int_case = big->is_long ? BIGINT_SIZE - 8 : BIGINT_SIZE - 7;
	big->first_dec_case = expo >= 0 ? BIGINT_SIZE - 7 : 1;
	big->last_dec_case = get_last_dec_case(expo, prec, big);
	big->last_digit_rank = get_last_digit_rank(expo, prec, big);
	big->next_figure = get_next_figure(big);
}
