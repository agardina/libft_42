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

static void	print_no_format(t_conv *conv, char **str)
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

static int	print_format_string(va_list ap, t_conv *conv, char **str)
{
	static int	(*f[11])(va_list ap, t_conv *c) = {&print_c,
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

static int	ft_printf_loop(int fd, const char *restrict format, va_list ap)
{
	t_conv	conv;
	char	*p;
	int		ret;

	conv.fd = fd;
	(conv.buf).index = 0;
	conv.res = 0;
	p = (char *)format;
	while (*p)
	{
		if (*p && *p != '%')
			print_no_format(&conv, &p);
		else if (*p && *p == '%')
			print_format_string(ap, &conv, &p);
	}
	ret = print_buffer(conv.fd, &(conv.buf));
	if (ret == -1)
		return (-1);
	return (conv.res);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_printf_loop(1, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_printf_loop(fd, format, ap);
	va_end(ap);
	return (ret);
}
