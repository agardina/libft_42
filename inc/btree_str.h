/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:10:09 by agardina          #+#    #+#             */
/*   Updated: 2021/07/27 19:10:12 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_STR_H

# define BTREE_STR_H

# include "libft.h"

typedef struct s_btree_node
{
	char				*content;
	struct s_btree_node	*left_child;
	struct s_btree_node	*right_child;
	struct s_btree_node	*parent;
	int					count;
}	t_btree_node;

typedef struct s_btree
{
	t_btree_node	*root;
	unsigned int	nb_nodes;
}	t_btree;

int		ft_btree_str_add_node(t_btree *tree, char *content);
void	ft_btree_str_clean(t_btree *tree);
void	ft_btree_str_init(t_btree *tree);

#endif
