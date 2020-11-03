/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:06:14 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:36:30 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		print_big_dbl(int16_t expo, t_conv *conv, t_bigint *big)
{
	int				res;
	unsigned int	last_case_to_print;

	last_case_to_print = (big->tab)[big->last_dec_case];
	cut_tab(big);
	round_up_bigint(big, last_case_to_print);
	res = print_int_part(big, expo, conv->prec, conv);
	if (conv->prec || conv->hashtag)
		putc_no_format(conv, '.');
	if (conv->prec)
		print_dec_part(big, conv->prec, expo, conv);
	return (res + (conv->prec > 0 ? conv->prec + 1 : 0));
}

void	print_first_dec(unsigned int nb, int *prec, int *index, t_conv *conv)
{
	int	i;
	int	len;
	int	mod;
	int	min;

	i = 0;
	mod = 1;
	min = ft_min(*prec, 6);
	if ((len = get_uint_len(nb)) > min)
	{
		while (i < min)
		{
			mod *= 10;
			i++;
		}
		nb = nb % mod;
	}
	put_zeros(min - get_uint_len(nb), conv);
	ft_putnbr_buf(conv, nb);
	*prec -= min;
	(*index)++;
}
