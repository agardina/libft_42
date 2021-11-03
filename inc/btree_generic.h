/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_generic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:14:24 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 15:14:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_GENERIC_H

# define BTREE_GENERIC_H

# include "libft.h"

typedef struct s_btree_gen_node
{
	void					*content;
	struct s_btree_gen_node	*left_child;
	struct s_btree_gen_node	*right_child;
	struct s_btree_gen_node	*parent;
	int						count;
	char					padding[4];
}	t_btree_gen_node;

typedef struct s_btree_gen
{
	t_btree_gen_node	*root;
	void				*(*create_content)(void *content);
	void				(*free_content)(void **content);
	int					(*cmp_content)(void *content1, void *content2);
	unsigned int		nb_nodes;
	char				padding[4];
}	t_btree_gen;

int		ft_btree_gen_add_node(t_btree_gen *tree, void *content);
void	ft_btree_gen_clean(t_btree_gen *tree);
int		ft_btree_gen_init(t_btree_gen *tree);

#endif
