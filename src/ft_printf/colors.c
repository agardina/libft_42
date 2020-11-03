/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:34:41 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:42:13 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"

int	get_color(char **str, t_conv *conv)
{
	static t_color	colors[17] = {{"black", "\033[30m"}, {"red", "\033[31m"},
		{"green", "\033[32m"}, {"yellow", "\033[33m"}, {"blue", "\033[34m"},
		{"magenta", "\033[35m"}, {"cyan", "\033[36m"}, {"light gray",
		"\033[37m"}, {"dark gray", "\033[90m"}, {"light red", "\033[91m"},
		{"light green", "\033[92m"}, {"light yellow", "\033[93m"},
		{"light blue", "\033[94m"}, {"light magenta", "\033[95m"},
		{"light cyan", "\033[96m"}, {"white", "\033[97m"}, {"eoc", "\033[0m"}};
	int				i;

	(*str)++;
	i = 0;
	while (i < 17)
	{
		if (ft_strnstr(*str, colors[i].name, ft_strlen(colors[i].name)))
		{
			return (color_found(str, colors[i], conv));
		}
		i++;
	}
	(*str)--;
	return (0);
}

int	color_found(char **str, t_color color, t_conv *conv)
{
	puts_no_format(conv, color.format, ft_strlen(color.format));
	*str += ft_strlen(color.name) + 1;
	return (1);
}
