/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:09:13 by agardina          #+#    #+#             */
/*   Updated: 2019/04/24 13:39:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	ft_strcpy(new, s);
	i = 0;
	while (new[i])
	{
		new[i] = (*f)(new[i]);
		i++;
	}
	return (new);
}
