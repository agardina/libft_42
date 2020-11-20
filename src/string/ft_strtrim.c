/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:42:50 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:45:34 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	start = i;
	i = (int)ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	end = i;
	if (!(new = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
