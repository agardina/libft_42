/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vector_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:59:15 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 15:59:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** \brief Delete an array of strings
**
** \param array the array of strings to delete
** \param size the size of the array of strings
*/
static void	delete_str_array(char ***array, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < size)
	{
		free((*array)[j]);
		j++;
	}
	free(*array);
	*array = NULL;
}

/**
** \brief Copy the old array of strings of the given string vector to the
** newly allocated array of strings
**
** \param vect the string vector
** \param new the newly allocated array of strings
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	copy_str_array(t_str_vector *vect, char ***new)
{
	unsigned int	i;

	i = 0;
	while (i < vect->used_size)
	{
		(*new)[i] = ft_strdup(vect->tab[i]);
		if (!(*new)[i])
		{
			delete_str_array(new, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	str_vector_realloc(t_str_vector *vect)
{
	char			**new;

	if (!vect)
		return (1);
	new = (char **)ft_memalloc(sizeof(char *) * vect->total_size * 2);
	if (!new)
		return (1);
	if (vect->tab)
	{
		if (copy_str_array(vect, &new))
			return (1);
	}
	delete_str_array(&(vect->tab), vect->used_size);
	vect->tab = new;
	vect->total_size = vect->total_size * 2;
	return (0);
}
