/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str_until_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:47:01 by agardina          #+#    #+#             */
/*   Updated: 2021/06/27 16:47:02 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy_str_until_char_excl(const char *src, const char c,
	const int copy_if_no_char)
{
	char			*p;
	char			*new;
	unsigned int	len;

	if (!src)
		return (NULL);
	p = ft_strchr(src, c);
	if (!p && copy_if_no_char)
	{
		new = ft_strdup(src);
		if (!new)
			return (NULL);
	}
	if (p)
	{
		len = ft_strlen(src) - ft_strlen(p);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (!new)
			return (NULL);
		ft_strncpy(new, src, len);
		new[len] = '\0';
	}
	return (new);
}
