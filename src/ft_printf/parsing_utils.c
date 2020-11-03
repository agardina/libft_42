/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:02:19 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 13:02:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	init_conv(t_conv *c)
{
	c->minus = 0;
	c->plus = 0;
	c->zero = 0;
	c->space = 0;
	c->hashtag = 0;
	c->width = 0;
	c->prec = -1;
	c->int_size = 0;
	c->f_size = 0;
	c->other_char = 0;
	c->type = 0;
}

int		is_conv_char(char c)
{
	return (is_lm(c) || ft_isdigit(c) || c == '.' || c == '-'
			|| c == '#' || c == '+' || c == ' ' || c == '*');
}

int		is_lm(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f');
}
