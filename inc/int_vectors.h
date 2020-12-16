/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vectors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:39:48 by agardina          #+#    #+#             */
/*   Updated: 2020/11/09 16:39:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_VECTORS_H

# define INT_VECTORS_H
# define INT_VECTOR_INIT_SIZE 1000

typedef struct		s_int_vector
{
	int				*tab;
	unsigned int	length;
	unsigned int	total_size;
}					t_int_vector;

char				int_vector_append(t_int_vector *vect, int nb);
t_int_vector		*int_vector_create(void);
void				int_vector_destroy(t_int_vector **vect);
void				int_vector_print(t_int_vector *vect);
void				int_vector_realloc(t_int_vector *vect);
char				is_int_vector_sorted(t_int_vector *vect);

#endif
