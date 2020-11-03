/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_inf_nan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:34:03 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:34:08 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	deal_inf_nan_dbl(t_conv *conv, t_dbl dbl)
{
	if (!dbl.mant && dbl.sign)
		return (print_inf_nan(conv, "-inf"));
	else if (!dbl.mant && !dbl.sign)
		return (print_inf_nan(conv, "inf"));
	else
		return (print_inf_nan(conv, "nan"));
}

int	deal_inf_nan_ldbl(t_conv *conv, t_ldbl ldbl)
{
	uint16_t mant;

	mant = ldbl.bits.u[3];
	if (mant == 0x8000 && ldbl.sign)
		return (print_inf_nan(conv, "-inf"));
	else if (mant == 0x8000 && !ldbl.sign)
		return (print_inf_nan(conv, "inf"));
	else
		return (print_inf_nan(conv, "nan"));
}

int	print_inf_nan(t_conv *conv, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (!conv->minus)
	{
		if (!conv->zero)
			put_spaces(conv->width - len, conv);
		else
			put_zeros(conv->width - len, conv);
	}
	puts_no_format(conv, str, len);
	if (conv->minus)
		put_spaces(conv->width - len, conv);
	return (conv->width - len > 0 ? conv->width : len);
}
