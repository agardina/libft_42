/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:29:40 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:29:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_prototypes.h"
#include "dict.h"

void				dict_dump(t_dict *dict)
{
	unsigned int	i;
	t_dict_entry	*ptr;

	i = 0;
	while (i < DICT_SIZE)
	{
		ptr = dict->entries[i];
		ft_printf("%d", i);
		while (ptr)
		{
			ft_printf("	Key: %s	Value: %s", ptr->key, ptr->value);
			ptr = ptr->next;
		}
		ft_printf("\n");
		i++;
	}
}
