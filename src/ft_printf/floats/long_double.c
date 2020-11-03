/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:01:26 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:27:52 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_lf(va_list ap, t_conv *conv)
{
	t_ldbl			ldbl;
	unsigned int	len;
	t_bigint		big;
	int				prefix_len;

	len = 0;
	ldbl.bits.f = (long double)va_arg(ap, long double);
	get_ld_info(&ldbl, conv, &len);
	prefix_len = (ldbl.sign == 1 || conv->plus || conv->space) ? 1 : 0;
	if (ldbl.expo + 16383 == 0b111111111111111)
		return (deal_inf_nan_ldbl(conv, ldbl));
	stock_ldbl(&ldbl, &big, conv->prec, &len);
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - len - prefix_len, conv);
	print_f_prefix(conv, ldbl.sign);
	if (conv->zero)
		put_zeros(conv->width - len - prefix_len, conv);
	put_ldbl_buffer(ldbl.expo, &big, conv);
	if (conv->minus)
		put_spaces(conv->width - len - prefix_len, conv);
	return (ft_max(len + prefix_len, conv->width));
}

void	get_ld_info(t_ldbl *ldbl, t_conv *conv, unsigned int *len)
{
	if ((ldbl->sign = ldbl->bits.u[4] >> 15))
		ldbl->bits.u[4] = ldbl->bits.u[4] ^ 0x8000;
	ldbl->expo = (((ldbl->bits.u[4]) << 1) >> 1) - 16383;
	if (conv->prec == -1)
		conv->prec = 6;
	if (conv->hashtag || conv->prec > 0)
		(*len)++;
}

void	stock_ldbl(t_ldbl *ldbl, t_bigint *big, int prec, unsigned int *len)
{
	if (ldbl->expo >= 0)
		store_big_ldbl(*ldbl, big);
	else
		store_small_ldbl(*ldbl, big);
	big->is_long = 1;
	get_bigint_info(big, ldbl->expo, prec);
	if (ldbl->expo < 0)
		*len += prec > 0 ? prec + 1 : 1;
	else
	{
		*len += get_uint_len((big->tab)[big->first_int_case]);
		*len += (BIGINT_SIZE - 8 - big->first_int_case) * 9;
		*len += prec > 0 ? prec : 0;
	}
}

int		put_ldbl_buffer(int16_t expo, t_bigint *big, t_conv *conv)
{
	if (expo >= 0)
		return (print_big_dbl(expo, conv, big));
	return (print_small_dbl(expo, conv, big));
}
