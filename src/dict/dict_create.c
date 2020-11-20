/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:29:33 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:29:36 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dict.h"

t_dict				*dict_create(void)
{
	t_dict			*new;
	unsigned int	i;

	if (!(new = (t_dict*)malloc(sizeof(t_dict))))
		return (NULL);
	new->entries = (t_dict_entry**)malloc(sizeof(t_dict_entry*) * DICT_SIZE);
	if (!new->entries)
		return (NULL);
	i = 0;
	while (i < DICT_SIZE)
		new->entries[i++] = NULL;
	return (new);
}
