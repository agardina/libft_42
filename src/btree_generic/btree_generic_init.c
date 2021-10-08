/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_generic_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:14:44 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 15:14:45 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btree_gen_init(t_btree_gen *tree)
{
	tree->cmp_content = NULL;
	tree->create_content = NULL;
	tree->free_content = NULL;
	tree->nb_nodes = 0;
	tree->root = NULL;
	return (0);
}
