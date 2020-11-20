/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:25:59 by agardina          #+#    #+#             */
/*   Updated: 2019/04/12 20:04:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	u;
	size_t			i;

	i = 0;
	u = (unsigned char)c;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (*(ptr + i) == u)
			return (ptr + i);
		else
			i++;
	}
	return (NULL);
}
