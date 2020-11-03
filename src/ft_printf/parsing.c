/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:23 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:35:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	get_conv_info(va_list ap, char **str, t_conv *conv)
{
	while (**str && is_conv_char(**str))
	{
		if (**str == '-')
			conv->minus = 1;
		else if (**str == '+')
			conv->plus = 1;
		else if (**str == '0')
			conv->zero = 1;
		else if (**str == ' ')
			conv->space = 1;
		else if (**str == '#')
			conv->hashtag = 1;
		else if (**str == '*' || (ft_isdigit(**str) && **str != '0'))
			get_width(ap, str, conv);
		else if (**str == '.')
			get_prec(ap, str, conv);
		else if (is_lm(**str))
			get_length(str, conv);
		(*str)++;
	}
	if (**str)
		get_type(str, conv);
	set_prio_flags(conv);
}

void	get_prec(va_list ap, char **str, t_conv *conv)
{
	(*str)++;
	conv->prec = 0;
	if (**str == '*')
	{
		if ((conv->prec = va_arg(ap, int)) < 0)
			conv->prec = -1;
	}
	else
	{
		if (**str)
		{
			while (**str && ft_isdigit(**str))
			{
				conv->prec = (conv->prec * 10) + **str - '0';
				(*str)++;
			}
		}
		(*str)--;
	}
}

void	get_width(va_list ap, char **str, t_conv *conv)
{
	conv->width = 0;
	if (**str == '*')
	{
		if ((conv->width = va_arg(ap, int)) < 0)
		{
			conv->minus = 1;
			conv->width *= -1;
		}
	}
	else
	{
		while (**str && ft_isdigit(**str))
		{
			conv->width = (conv->width * 10) + **str - '0';
			(*str)++;
		}
		(*str)--;
	}
}

void	get_length(char **str, t_conv *conv)
{
	int	new_int_size;
	int	new_f_size;

	new_int_size = 0;
	new_f_size = 0;
	while (**str && is_lm(**str))
	{
		if (**str == 'h' && *(*str + 1) == 'h')
			new_int_size = SIZE_HH;
		else if (**str == 'h')
			new_int_size = SIZE_H;
		else if (**str == 'l' && *(*str + 1) == 'l')
			new_int_size = SIZE_LL;
		else if (**str == 'l')
			new_int_size = SIZE_L;
		else if (**str == 'L')
			new_f_size = SIZE_LF;
		conv->int_size = ft_max(new_int_size, conv->int_size);
		conv->f_size = ft_max(new_f_size, conv->f_size);
		(*str)++;
		if (new_int_size == SIZE_HH || new_int_size == SIZE_LL)
			(*str)++;
	}
	(*str)--;
}

void	set_prio_flags(t_conv *conv)
{
	if (conv->type != TYPE_B)
	{
		if (conv->zero && conv->minus)
			conv->zero = 0;
		if (conv->space && conv->plus)
			conv->space = 0;
		if (conv->prec > -1 && (conv->type == TYPE_D || conv->type == TYPE_O
					|| conv->type == TYPE_U || conv->type == TYPE_X
					|| conv->type == TYPE_BIG_X))
			conv->zero = 0;
	}
}
