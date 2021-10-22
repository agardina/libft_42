/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:20:10 by agardina          #+#    #+#             */
/*   Updated: 2021/10/22 15:20:11 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
