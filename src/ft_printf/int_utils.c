/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:26:54 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:28:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int					get_uint_len(unsigned long long nb)
{
	int	res;

	res = 1;
	while (nb / 10)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

void				ft_putnbr_buf(t_conv *conv, unsigned long long nb)
{
	if (nb / 10)
		ft_putnbr_buf(conv, nb / 10);
	putc_no_format(conv, (nb % 10) + '0');
}

void				ft_putnbr_base_buf(t_conv *conv, unsigned long long nb,
		char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (nb / len)
		ft_putnbr_base_buf(conv, nb / len, base);
	putc_no_format(conv, base[nb % len]);
}

int					get_convert_len(unsigned long long nb, t_conv *conv)
{
	int	res;
	int	len;

	if (conv->type == TYPE_O)
		len = 8;
	else if (conv->type == TYPE_B)
		len = 2;
	else
		len = 16;
	res = 1;
	nb /= len;
	while (nb)
	{
		res++;
		nb /= len;
	}
	return (res);
}
