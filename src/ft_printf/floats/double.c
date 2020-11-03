/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:55:33 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:28:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_f(va_list ap, t_conv *conv)
{
	t_dbl			dbl;
	unsigned int	len;
	t_bigint		big;
	int				prefix_len;

	len = 0;
	dbl.bits.f = (double)va_arg(ap, double);
	get_d_info(&dbl, conv, &len);
	prefix_len = (dbl.sign == 1 || conv->plus || conv->space) ? 1 : 0;
	if (dbl.expo + 1023 == 0b11111111111)
		return (deal_inf_nan_dbl(conv, dbl));
	stock_dbl(&dbl, &big, conv->prec, &len);
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - len - prefix_len, conv);
	print_f_prefix(conv, dbl.sign);
	if (conv->zero)
		put_zeros(conv->width - len - prefix_len, conv);
	put_dbl_buffer(dbl.expo, conv, &big);
	if (conv->minus)
		put_spaces(conv->width - len - prefix_len, conv);
	return (ft_max(len + prefix_len, conv->width));
}

void	get_d_info(t_dbl *dbl, t_conv *conv, unsigned int *len)
{
	if ((dbl->sign = dbl->bits.u >> 63))
		dbl->bits.u = dbl->bits.u ^ 0x8000000000000000;
	dbl->expo = (((dbl->bits.u) << 1) >> 53) - 1023;
	dbl->mant = (dbl->bits.u) << 12;
	if (conv->prec == -1)
		conv->prec = 6;
	if (conv->hashtag || conv->prec > 0)
		(*len)++;
}

void	stock_dbl(t_dbl *dbl, t_bigint *big, int prec, unsigned int *len)
{
	if (dbl->expo >= 0)
		store_big_dbl(*dbl, big);
	else
		store_small_dbl(*dbl, big);
	big->is_long = 0;
	get_bigint_info(big, dbl->expo, prec);
	if (dbl->expo < 0)
		*len += prec > 0 ? prec + 1 : 1;
	else
	{
		if (big->first_int_case < BIGINT_SIZE - 7)
		{
			*len += get_uint_len((big->tab)[big->first_int_case]);
			*len += (BIGINT_SIZE - 8 - big->first_int_case) * 9 + 3;
		}
		else
		{
			*len += get_uint_len(div_by_10((big->tab)[big->last_int_case], 6));
		}
		*len += prec > 0 ? prec : 0;
	}
}

int		put_dbl_buffer(int16_t expo, t_conv *conv, t_bigint *big)
{
	if (expo >= 0)
		return (print_big_dbl(expo, conv, big));
	return (print_small_dbl(expo, conv, big));
}

void	print_f_prefix(t_conv *conv, int sign)
{
	if (!sign && conv->plus)
		putc_no_format(conv, '+');
	else if (!sign && conv->space)
		putc_no_format(conv, ' ');
	else if (sign == 1)
		putc_no_format(conv, '-');
}
