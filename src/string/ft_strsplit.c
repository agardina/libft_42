/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:54:57 by agardina          #+#    #+#             */
/*   Updated: 2019/04/24 14:22:51 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	char *separator;

	if (!s || !c)
		return (NULL);
	if ((separator = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	separator[0] = c;
	separator[1] = '\0';
	return (ft_split(s, separator));
}
