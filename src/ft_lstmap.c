/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:31:01 by agardina          #+#    #+#             */
/*   Updated: 2019/04/21 21:31:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *current;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if ((first = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	first = (*f)(lst);
	current = first;
	lst = lst->next;
	while (lst)
	{
		if ((tmp = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		tmp = (*f)(lst);
		current->next = tmp;
		current = tmp;
		free(tmp);
		lst = lst->next;
	}
	return (first);
}
