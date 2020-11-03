/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:29:04 by agardina          #+#    #+#             */
/*   Updated: 2020/02/13 15:29:57 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_conv	conv;
	char	*p;

	if (!format)
		return (-1);
	(conv.buf).index = 0;
	conv.res = 0;
	p = (char *)format;
	va_start(ap, format);
	while (*p)
	{
		if (*p && *p != '%')
			print_no_format(&conv, &p);
		if (*p && *p == '%')
			print_format_string(ap, &conv, &p);
	}
	print_buffer(&(conv.buf));
	va_end(ap);
	return (conv.res);
}

void	print_no_format(t_conv *conv, char **str)
{
	while (**str && **str != '%')
	{
		if (**str != '{')
		{
			putc_no_format(conv, **str);
			(*str)++;
		}
		else
		{
			if (!get_color(str, conv))
			{
				putc_no_format(conv, **str);
				(*str)++;
			}
		}
	}
}

int		print_format_string(va_list ap, t_conv *conv, char **str)
{
	static int	(*f[11]) (va_list ap, t_conv *c) = {&print_c,
		&print_d, &print_f, &print_lf, &print_o, &print_p, &print_s,
		&print_u, &print_x, &print_big_x, &print_b};

	(*str)++;
	if (!(**str))
		return (0);
	init_conv(conv);
	get_conv_info(ap, str, conv);
	f[conv->type](ap, conv);
	return (1);
}
