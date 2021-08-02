/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_str_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:09:42 by agardina          #+#    #+#             */
/*   Updated: 2021/07/27 19:09:45 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_btree_str_clean_nodes(t_btree_str *tree, t_btree_str_node *node)
{
	if (node->left_child)
		ft_btree_str_clean_nodes(tree, node->left_child);
	if (node->right_child)
		ft_btree_str_clean_nodes(tree, node->right_child);
	free(node->content);
	free(node);
}

void	ft_btree_str_clean(t_btree_str *tree)
{
	if (tree->root)
		ft_btree_str_clean_nodes(tree, tree->root);
	tree->root = NULL;
	tree->nb_nodes = 0;
}
