/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:23:46 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:23:52 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	print_buffer(int fd, t_buf *buf)
{
	ssize_t	ret;

	ret = write(fd, buf->b, buf->index);
	if (ret == -1)
		return (-1);
	return (0);
}

int	putc_no_format(t_conv *conv, char c)
{
	if ((conv->buf).index == FT_PRINTF_BUFF_SIZE - 1)
	{
		print_buffer(conv->fd, &(conv->buf));
		(conv->buf).index = 0;
	}
	(conv->buf).b[(conv->buf).index] = c;
	(conv->buf).index++;
	conv->res++;
	return (1);
}

void	puts_no_format(t_conv *conv, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		putc_no_format(conv, str[i]);
		i++;
	}
}

void	put_spaces(int nb, t_conv *conv)
{
	int	count;

	count = nb;
	if (count > 0)
	{
		while (count--)
			putc_no_format(conv, ' ');
	}
}

void	put_zeros(int nb, t_conv *conv)
{
	int	count;

	count = nb;
	if (count > 0)
	{
		while (count--)
			putc_no_format(conv, '0');
	}
}
