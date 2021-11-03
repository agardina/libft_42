/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:47:36 by agardina          #+#    #+#             */
/*   Updated: 2021/06/27 16:47:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_trim_str_until_char_excl(char **str, const char c,
	const int delete_if_no_char)
{
	char			*p;
	char			*new;
	unsigned int	len;

	if (!str || !*str)
		return (1);
	p = ft_strchr(*str, c);
	if (!p && delete_if_no_char)
	{
		free(*str);
		*str = NULL;
	}
	if (p)
	{
		len = ft_strlen(*str) - ft_strlen(p);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (!new)
			return (1);
		ft_strncpy(new, *str, len);
		new[len] = '\0';
		free(*str);
		*str = new;
	}
	return (0);
}

int	ft_trim_str_after_char_excl(char **str, const char c,
	const int delete_if_no_char)
{
	char			*p;
	char			*new;
	unsigned int	len;

	if (!str || !*str)
		return (1);
	p = ft_strchr(*str, c);
	if (!p && delete_if_no_char)
	{
		free(*str);
		*str = NULL;
	}
	if (p)
	{
		p++;
		len = ft_strlen(p);
		new = ft_strdup(p);
		if (!new)
			return (1);
		new[len] = '\0';
		free(*str);
		*str = new;
	}
	return (0);
}
