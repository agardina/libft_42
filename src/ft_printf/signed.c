/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:36:54 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:39:12 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int				print_d(va_list ap, t_conv *conv)
{
	long long int	nb;
	unsigned int	len;
	int				prefix_len;

	nb = convert_s_number(ap, conv);
	len = (!nb && !conv->prec) ? 0 : get_uint_len(ft_abs(nb));
	prefix_len = (nb < 0 || conv->plus || conv->space) ? 1 : 0;
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, conv);
	print_s_prefix(nb, conv);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len, conv);
		else
			put_zeros(conv->width - len - prefix_len, conv);
	}
	if (len)
		ft_putnbr_buf(conv, ft_abs(nb));
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec)
				- prefix_len, conv);
	return (ft_max(ft_max(len + prefix_len, conv->prec + prefix_len),
				conv->width));
}

void			print_s_prefix(long long nb, t_conv *conv)
{
	if (nb >= 0 && conv->plus)
		putc_no_format(conv, '+');
	else if (nb >= 0 && conv->space)
		putc_no_format(conv, ' ');
	else if (nb < 0)
		putc_no_format(conv, '-');
}

long long int	convert_s_number(va_list ap, t_conv *conv)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	if (conv->int_size == SIZE_HH)
		return ((signed char)nb);
	else if (conv->int_size == SIZE_H)
		return ((signed short)nb);
	else if (conv->int_size == SIZE_L)
		return ((signed long)nb);
	else if (conv->int_size == SIZE_LL)
		return ((signed long long)nb);
	return ((signed int)nb);
}
