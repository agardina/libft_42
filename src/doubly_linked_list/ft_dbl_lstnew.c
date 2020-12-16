/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:24:04 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:34:56 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list_elt	*ft_dbl_lstnew(void const *content, size_t content_size)
{
	t_dbl_list_elt	*new;

	if (!(new = (t_dbl_list_elt*)malloc(sizeof(t_dbl_list_elt))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
