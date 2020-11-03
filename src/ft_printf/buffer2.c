/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:24:27 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:24:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	print_padding(t_conv *conv, int len)
{
	if (conv->zero)
		put_zeros(len, conv);
	else
		put_spaces(len, conv);
}
