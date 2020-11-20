/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:38:57 by agardina          #+#    #+#             */
/*   Updated: 2019/04/21 14:37:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t result;
	size_t i;
	size_t j;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (size <= j)
	{
		result = i + size;
		return (result);
	}
	else
		result = i + j;
	i = 0;
	while (src[i] && i + j < size - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (result);
}
