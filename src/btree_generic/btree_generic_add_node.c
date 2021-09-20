/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_generic_add_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:14:35 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 15:14:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_btree_gen_node	*ft_btree_gen_create_node(t_btree_gen *tree,
	void *content)
{
	t_btree_gen_node	*new;

	new = (t_btree_gen_node *)malloc(sizeof(t_btree_gen_node));
	if (!new)
		return (NULL);
	new->left_child = NULL;
	new->right_child = NULL;
	new->parent = NULL;
	new->count = 1;
	if (tree->create_content)
		new->content = tree->create_content(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static void	ft_btree_gen_insert_duplicate(t_btree_gen *tree,
	t_btree_gen_node *parent, t_btree_gen_node **new)
{
	parent->count++;
	if (tree->free_content)
		tree->free_content(&(*new)->content);
	free(*new);
	*new = NULL;
}

static void	ft_btree_gen_node_insertion(t_btree_gen *tree,
	t_btree_gen_node *parent, t_btree_gen_node **new, int left_child)
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

static void	ft_btree_gen_insert_node(t_btree_gen *tree,
	t_btree_gen_node *parent, t_btree_gen_node **new)
{
	int	ret;

	ret = 0;
	if (tree->compare_content)
		ret = tree->compare_content((*new)->content, parent->content);
	if (ret == 0)
		return (ft_btree_gen_insert_duplicate(tree, parent, new));
	if (ret < 0 && !parent->left_child)
		return (ft_btree_gen_node_insertion(tree, parent, new, 1));
	else if (ret > 0 && !parent->right_child)
		return (ft_btree_gen_node_insertion(tree, parent, new, 0));
	else
	{
		if (ret > 0)
			ft_btree_gen_insert_node(tree, parent->right_child, new);
		else
			ft_btree_gen_insert_node(tree, parent->left_child, new);
	}
}

int	ft_btree_gen_add_node(t_btree_gen *tree, void *content)
{
	t_btree_gen_node	*new;

	new = ft_btree_gen_create_node(tree, content);
	if (!new)
		return (-1);
	if (!tree->root)
	{
		tree->root = new;
		tree->nb_nodes++;
	}
	else
		ft_btree_gen_insert_node(tree, tree->root, &new);
	return (0);
}
