/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_small_dbl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:27:51 by agardina          #+#    #+#             */
/*   Updated: 2020/02/13 16:28:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_small_dbl(int16_t expo, t_conv *conv, t_bigint *big)
{
	unsigned int last_case_to_print;

	last_case_to_print = (big->tab)[big->last_dec_case];
	cut_tab(big);
	round_up_bigint(big, last_case_to_print);
	print_int_part(big, expo, conv->prec, conv);
	if (conv->prec || conv->hashtag)
		putc_no_format(conv, '.');
	if (conv->prec)
		print_dec_part(big, conv->prec, expo, conv);
	return (1 + (conv->prec > 0 ? conv->prec + 1 : 0));
}
