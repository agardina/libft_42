/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:29:53 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:29:58 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dict.h"

static t_dict_entry	*dict_pair(char *key, char *value)
{
	t_dict_entry	*new;
	unsigned int	len;

	if (!(new = (t_dict_entry*)malloc(sizeof(t_dict_entry))))
		return (NULL);
	len = ft_strlen(key);
	if (!(new->key = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(new->key, key);
	len = ft_strlen(value);
	if (!(new->value = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(new->value, value);
	new->next = NULL;
	return (new);
}

static char			dict_update_value(t_dict_entry *entry, char *value)
{
	free(entry->value);
	entry->value = (char*)malloc(sizeof(char) * (ft_strlen(value) + 1));
	if (!entry->value)
		return (1);
	ft_strcpy(entry->value, value);
	return (0);
}

char				dict_set(t_dict *dict, char *key, char *value)
{
	unsigned int	index;
	t_dict_entry	*ptr;
	t_dict_entry	*prev;

	index = hash(key);
	ptr = NULL;
	prev = NULL;
	if (!dict->entries[index])
	{
		if (!(dict->entries[index] = dict_pair(key, value)))
			return (1);
		return (0);
	}
	ptr = dict->entries[index];
	while (ptr)
	{
		if (ft_strequ(ptr->key, key))
			return (dict_update_value(ptr, value));
		prev = ptr;
		ptr = ptr->next;
	}
	if (!(prev->next = dict_pair(key, value)))
		return (1);
	return (0);
}
