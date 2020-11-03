/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:27:34 by agardina          #+#    #+#             */
/*   Updated: 2020/02/13 16:27:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_int_part(t_bigint *big, int16_t expo, int prec, t_conv *conv)
{
	int				res;
	unsigned int	last_digits;
	int				int_part_start;

	if (expo < 0)
	{
		ft_putnbr_buf(conv, (big->tab)[0]);
		return (1);
	}
	else
	{
		res = 0;
		int_part_start = 0;
		print_first_int_digits(big, &res, conv, &int_part_start);
		if (!big->is_long)
		{
			last_digits = (big->tab)[BIGINT_SIZE - 7];
			last_digits = div_by_10(last_digits, ft_min(prec, 6));
			if (int_part_start < BIGINT_SIZE - 7)
				put_zeros(3 - get_uint_len(last_digits), conv);
			ft_putnbr_buf(conv, last_digits);
			res += get_uint_len(last_digits);
		}
		return (res);
	}
}

void	print_first_int_digits(t_bigint *big, int *res, t_conv *conv,
		int *int_part_start)
{
	int	i;

	i = 0;
	while ((big->tab)[i] == 0)
		i++;
	*int_part_start = i;
	while (i < BIGINT_SIZE - 7)
	{
		if (i == *int_part_start)
			*res += get_uint_len((big->tab)[i]);
		else
			*res += 9;
		if (i > *int_part_start)
			filling_zeros(conv, (big->tab)[i]);
		ft_putnbr_buf(conv, (big->tab)[i]);
		i++;
	}
}
