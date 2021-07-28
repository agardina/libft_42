/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_generic_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:14:41 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 15:14:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_btree_gen_clean_nodes(t_btree_gen *tree, t_btree_gen_node *node)
{
	if (node->left_child)
		ft_btree_gen_clean_nodes(tree, node->left_child);
	if (node->right_child)
		ft_btree_gen_clean_nodes(tree, node->right_child);
	if (tree->free_content)
		tree->free_content(node->content);
	free(node);
}

void	ft_btree_gen_clean(t_btree_gen *tree)
{
	if (tree->root)
		ft_btree_gen_clean_nodes(tree, tree->root);
	tree->root = NULL;
	tree->nb_nodes = 0;
}
