/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:45:03 by agardina          #+#    #+#             */
/*   Updated: 2021/05/09 13:45:10 by agardina         ###   ########.fr       */
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
