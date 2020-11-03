/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:24:48 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:26:20 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	init_bigint(t_bigint *big)
{
	int	i;

	i = 0;
	while (i < BIGINT_SIZE)
	{
		(big->tab)[i] = 0;
		i++;
	}
}

void	create_unit(t_bigint *big, unsigned int size, int expo)
{
	int	i;

	i = 0;
	if ((size == 8 && expo >= 0) || (size == 16 && expo >= 0))
	{
		while (i < BIGINT_SIZE - 5)
		{
			(big->tab)[i] = 0;
			i++;
		}
		(big->tab)[BIGINT_SIZE - 1] = size == 8 ? 500000000 : 142578125;
		(big->tab)[BIGINT_SIZE - 2] = size == 8 ? 618164062 : 86994171;
		(big->tab)[BIGINT_SIZE - 3] = size == 8 ? 84726333 : 400745280;
		(big->tab)[BIGINT_SIZE - 4] = size == 8 ? 925031308 : 248550443;
		(big->tab)[BIGINT_SIZE - 5] = size == 8 ? 222044604 : 108420217;
	}
	else
	{
		(big->tab)[0] = 0;
		i = 0;
		(big->tab)[i + 1] = 500000000;
		while (++i < BIGINT_SIZE)
			(big->tab)[i + 1] = 0;
	}
}

void	filling_zeros(t_conv *conv, unsigned int nb)
{
	if (nb < 100000000)
		putc_no_format(conv, '0');
	if (nb < 10000000)
		putc_no_format(conv, '0');
	if (nb < 1000000)
		putc_no_format(conv, '0');
	if (nb < 100000)
		putc_no_format(conv, '0');
	if (nb < 10000)
		putc_no_format(conv, '0');
	if (nb < 1000)
		putc_no_format(conv, '0');
	if (nb < 100)
		putc_no_format(conv, '0');
	if (nb < 10)
		putc_no_format(conv, '0');
}

int		only_nine(unsigned int nb)
{
	if (!nb)
		return (0);
	while (nb)
	{
		if (nb % 10 == 9)
			nb /= 10;
		else
			return (0);
	}
	return (1);
}
