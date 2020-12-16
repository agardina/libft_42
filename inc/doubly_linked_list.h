/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:23:13 by agardina          #+#    #+#             */
/*   Updated: 2020/12/16 11:34:08 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H

# define DOUBLY_LINKED_LIST_H
# include "libft.h"

typedef struct				s_dbl_list_elt
{
	void					*content;
	size_t					content_size;
	struct s_dbl_list_elt	*prev;
	struct s_dbl_list_elt	*next;
}							t_dbl_list_elt;

typedef struct				s_dbl_list
{
	t_dbl_list_elt			*head;
	t_dbl_list_elt			*tail;
	unsigned int			size;
	void					(*del)(void *content, size_t content_size);
}							t_dbl_list;

void						ft_dbl_lstadd(t_dbl_list *list,
								t_dbl_list_elt *new);
void						ft_dbl_lstadd_tail(t_dbl_list *list,
								t_dbl_list_elt *new);
void						ft_dbl_lstdel(t_dbl_list *list);
void						ft_dbl_lstdelone(t_dbl_list *list,
								t_dbl_list_elt *e);
void						ft_dbl_lstinit(t_dbl_list *list,
								void (*del)(void *, size_t));
t_dbl_list_elt				*ft_dbl_lstnew(void const *content,
								size_t content_size);
unsigned int				ft_dbl_lstsize(t_dbl_list *list);

#endif
