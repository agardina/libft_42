/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:27:05 by agardina          #+#    #+#             */
/*   Updated: 2020/02/13 16:27:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_b(va_list ap, t_conv *conv)
{
	unsigned long long		nb;
	unsigned int			len;
	unsigned int			i;

	nb = convert_u_number(ap, conv);
	len = get_convert_len(nb, conv);
	if (conv->zero)
		len += len % 8 ? (8 - len % 8) : 0;
	i = 0;
	while (i < len)
	{
		putc_no_format(conv, ((nb >> (len - 1 - i)) & 1) + '0');
		if (conv->space && ((i + 1) % 8) == len % 8)
			putc_no_format(conv, ' ');
		i++;
	}
	return (len + (conv->space ? ((len - 1) / 8) : 0));
}
