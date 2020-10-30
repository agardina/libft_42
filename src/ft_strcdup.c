/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:46:53 by agardina          #+#    #+#             */
/*   Updated: 2019/09/19 11:08:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Cette fonction renvoie une copie de la chaîne de caractères str
** jusqu'au caractère c inclus (si incl_c est différent de 0) ou exclu
** (si incl_c vaut 0).
** Si c ne se trouve pas dans str, alors NULL est renvoyé si copy_all vaut 0,
** une copie de str est renvoyée si copy_all est différent de 0.
*/

char	*ft_strcdup(const char *str, char c, int incl_c, int copy_all)
{
	int		len;
	char	*new;
	int		i;
	char	*end;

	end = ft_strchr(str, c);
	if (!str || (!end && !copy_all))
		return (NULL);
	if ((!end && copy_all) || !c)
		len = ft_strlen(str);
	else
		len = end - str - (incl_c == 1 ? 0 : 1) + 1;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
