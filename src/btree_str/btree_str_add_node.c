#include "libft.h"

static t_btree_node	*ft_btree_str_create_node(char *content)
{
	t_btree_node	*new;

	new = (t_btree_node *)malloc(sizeof(t_btree_node));
	if (!new)
		return (NULL);
	new->left_child = NULL;
	new->right_child = NULL;
	new->parent = NULL;
	new->count = 1;
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static void	ft_btree_str_insert_duplicate(t_btree_node *parent, t_btree_node **new)
{
	parent->count++;
	free((*new)->content);
	free(*new);
	*new = NULL;
}

static void	ft_btree_str_node_insertion(t_btree *tree, t_btree_node *parent,
	t_btree_node **new, int left_child)
{
	if (left_child)
	{
		parent->left_child = *new;
		(*new)->parent = parent;
	}
	else
	{
		parent->right_child = *new;
		(*new)->parent = parent;
	}
	tree->nb_nodes++;
}

static void	ft_btree_str_insert_node(t_btree *tree, t_btree_node *parent,
	t_btree_node **new)
{
	int	ret;

	ret = ft_strcmp((*new)->content, parent->content);
	if (ret == 0)
		return (ft_btree_str_insert_duplicate(parent, new));
	if (ret < 0 && !parent->left_child)
		return (ft_btree_str_node_insertion(tree, parent, new, 1));
	else if (ret > 0 && !parent->right_child)
		return (ft_btree_str_node_insertion(tree, parent, new, 0));
	else
	{
		if (ret > 0)
			ft_btree_str_insert_node(tree, parent->right_child, new);
		else
			ft_btree_str_insert_node(tree, parent->left_child, new);
	}
}

int	ft_btree_str_add_node(t_btree *tree, char *content)
{
	t_btree_node	*new;

	new = ft_btree_str_create_node(content);
	if (!new)
		return (-1);
	if (!tree->root)
	{
		tree->root = new;
		tree->nb_nodes++;
	}
	else
		ft_btree_str_insert_node(tree, tree->root, &new);
	return (0);
}
