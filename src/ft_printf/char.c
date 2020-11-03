/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:24:43 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:25:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	print_c(va_list ap, t_conv *conv)
{
	int c;
	int res;

	if (conv->other_char)
		c = conv->other_char;
	else
		c = (char)va_arg(ap, int);
	if (!conv->minus)
		print_padding(conv, conv->width - 1);
	putc_no_format(conv, c);
	if (conv->minus)
		print_padding(conv, conv->width - 1);
	return (res = conv->width > 1 ? conv->width : 1);
}
