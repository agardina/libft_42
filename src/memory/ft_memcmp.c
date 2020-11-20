/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:43:52 by agardina          #+#    #+#             */
/*   Updated: 2019/04/16 15:37:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	p_s1 = (unsigned char*)s1;
	p_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*(p_s1 + i) != (unsigned char)*(p_s2 + i))
			return ((unsigned char)*(p_s1 + i) - (unsigned char)*(p_s2 + i));
		else
			i++;
	}
	return (0);
}
