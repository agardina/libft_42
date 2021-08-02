/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_vectors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:03:21 by agardina          #+#    #+#             */
/*   Updated: 2021/08/02 16:03:24 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  STR_VECTORS_H

# define STR_VECTORS_H
# define STR_VECTOR_INIT_SIZE 1000
# include "libft.h"

typedef struct s_str_vector
{
	char			**tab;
	unsigned int	used_size;
	unsigned int	total_size;
}	t_str_vector;

/**
** \brief Add a string to a string vector
**
** \param vect the string vector to add a string to
** \param str the string to add
**
** \retval 0 if success
** \retval 1 otherwise
*/
int				str_vector_append(t_str_vector *vect, char *str);
/**
** \brief Create a string vector
**
** \return a pointer to the created string vector if success, NULL otherwise
*/
t_str_vector	*str_vector_create(void);
/**
** \brief Destroy a string vector
**
** \param vect the string vector to destroy
*/
void			str_vector_destroy(t_str_vector **vect);
/**
** \brief Print the content of a string vector
**
** \param vect the string vector to print
*/
void			str_vector_print(t_str_vector *vect);
/**
** \brief Reallocate memory in order to increase the size of string vector
**
** \param vect the string vector to modify
**
** \retval 0 if success
** \retval 1 otherwise
*/
int				str_vector_realloc(t_str_vector *vect);

#endif
