/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:47:27 by agardina          #+#    #+#             */
/*   Updated: 2021/06/27 16:47:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_realloc(char **dst, const char *src)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	char			*new;

	if (!dst)
		return (NULL);
	if (!src)
		return (*dst);
	len_dst = ft_strlen(*dst);
	len_src = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (len_dst + len_src + 1));
	ft_strcpy(new, *dst);
	ft_strcat(new + len_dst, src);
	new[len_dst + len_src] = '\0';
	free(*dst);
	*dst = new;
	return (*dst);
}
