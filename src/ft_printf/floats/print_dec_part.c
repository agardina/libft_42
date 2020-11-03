/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:14:54 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 13:15:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	print_dec_part(t_bigint *big, int prec, int16_t expo, t_conv *conv)
{
	int	i;

	i = (expo >= 0 ? BIGINT_SIZE - 7 : 1);
	if (expo >= 0 && !big->is_long)
		print_first_dec((big->tab)[BIGINT_SIZE - 7], &prec, &i, conv);
	while (i <= big->last_dec_case)
	{
		if (i < big->last_dec_case || big->last_digit_rank == 0)
		{
			filling_zeros(conv, (big->tab)[i]);
			ft_putnbr_buf(conv, (big->tab)[i]);
			prec -= 9;
		}
		i++;
	}
	if (0 < prec && prec < 9 && big->last_digit_rank > 0)
	{
		put_zeros(prec - get_uint_len((big->tab)[i - 1]), conv);
		ft_putnbr_buf(conv, (big->tab)[i - 1]);
	}
	if (prec > 9)
		put_zeros(prec, conv);
}
