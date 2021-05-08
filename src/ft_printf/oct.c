/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:32:09 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:32:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

static	unsigned int	compute_len(unsigned long long int nb, t_conv *conv)
{
	if (!nb && (conv->prec == 0 || conv->hashtag))
		return (0);
	return (get_convert_len(nb, conv));
}

static	int	compute_prefix_len(t_conv *conv)
{
	if (conv->hashtag)
		return (1);
	return (0);
}

int	print_o(va_list ap, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;
	int						prefix_len;

	nb = convert_u_number(ap, conv);
	len = compute_len(nb, conv);
	prefix_len = compute_prefix_len(conv);
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len + prefix_len, conv->prec), conv);
	print_u_prefix(nb, conv);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len - prefix_len, conv);
		else
			put_zeros(conv->width - len - prefix_len, conv);
	}
	if (len)
		ft_putnbr_base_buf(conv, nb, "01234567");
	if (conv->minus)
		put_spaces(conv->width - ft_max(len + prefix_len, conv->prec), conv);
	return (ft_max(ft_max(len + prefix_len, conv->prec), conv->width));
}
