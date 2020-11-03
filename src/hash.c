/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:30:04 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:30:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"

unsigned int		hash(const char *key)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	value;

	len = ft_strlen(key);
	i = 0;
	value = 0;
	while (i < len)
	{
		value = value * 37 + key[i];
		i++;
	}
	return (value % DICT_SIZE);
}
