/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:36:50 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 12:36:53 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

void	get_type(char **str, t_conv *conv)
{
	if (**str == 'X')
		conv->type = TYPE_BIG_X;
	else if (**str == 'x')
		conv->type = TYPE_X;
	else if (**str == 'u')
		conv->type = TYPE_U;
	else if (**str == 's')
		conv->type = TYPE_S;
	else if (**str == 'p')
		conv->type = TYPE_P;
	else if (**str == 'o')
		conv->type = TYPE_O;
	else if (**str == 'f' && !conv->f_size)
		conv->type = TYPE_F;
	else if (**str == 'f' && conv->f_size)
		conv->type = TYPE_LF;
	else if (**str == 'b')
		conv->type = TYPE_B;
	else if (**str == 'd' || **str == 'i')
		conv->type = TYPE_D;
	else
		get_c_type(str, conv);
	(*str)++;
}

void	get_c_type(char **str, t_conv *conv)
{
	conv->type = TYPE_C;
	conv->other_char = **str != 'c' ? **str : 0;
}
