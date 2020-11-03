/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:29:46 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:29:48 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dict.h"

char				*dict_get(t_dict *dict, char *key)
{
	unsigned int	index;
	t_dict_entry	*ptr;

	index = hash(key);
	ptr = dict->entries[index];
	while (ptr)
	{
		if (ft_strequ(ptr->key, key))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
