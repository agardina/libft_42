/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:59 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:24:02 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstinit(t_dbl_list *list)
{
	if (!list)
		return ;
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
