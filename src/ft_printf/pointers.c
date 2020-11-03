/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:35:33 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:36:40 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	print_p(va_list ap, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;

	nb = convert_u_number(ap, conv);
	len = (!nb && !conv->prec) ? 0 : get_convert_len(nb, conv);
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec) - 2, conv);
	print_u_prefix(nb, conv);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len, conv);
		else
			put_zeros(conv->width - len - 2, conv);
	}
	if (len)
		ft_putnbr_base_buf(conv, nb, "0123456789abcdef");
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec) - 2, conv);
	return (ft_max(ft_max(len + 2, conv->prec + 2), conv->width));
}
