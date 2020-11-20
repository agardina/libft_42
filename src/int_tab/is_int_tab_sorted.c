/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_tab_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:59:52 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 17:00:12 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_int_tab_sorted(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
