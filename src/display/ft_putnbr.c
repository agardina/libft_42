/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:47:43 by agardina          #+#    #+#             */
/*   Updated: 2019/04/03 15:47:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	value;

	if (n < 0)
	{
		value = (unsigned int)(-n);
		ft_putchar('-');
	}
	else
		value = (unsigned int)n;
	if (value > 9)
		ft_putnbr(value / 10);
	ft_putchar((value % 10) + '0');
}
