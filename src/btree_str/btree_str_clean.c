#include "libft.h"

static void	ft_btree_str_clean_nodes(t_btree *tree, t_btree_node *node)
{
	if (node->left_child)
		ft_btree_str_clean_nodes(tree, node->left_child);
	if (node->right_child)
		ft_btree_str_clean_nodes(tree, node->right_child);
	free(node->content);
	free(node);
}

void	ft_btree_str_clean(t_btree *tree)
{
	if (tree->root)
		ft_btree_str_clean_nodes(tree, tree->root);
	tree->root = NULL;
	tree->nb_nodes = 0;
}
