/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:57:17 by agardina          #+#    #+#             */
/*   Updated: 2020/11/05 10:57:18 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_prototypes.h"

static void	sort_sub_table(int *tab, int imin, int imax, int *tmp)
{
	int	mid;
	int	cursor_left;
	int	cursor_right;
	int	tmp_index;

	mid = (imin + imax) / 2;
	cursor_left = imin;
	cursor_right = mid + 1;
	tmp_index = imin;
	while (tmp_index <= imax)
	{
		if ((tab[cursor_left] <= tab[cursor_right] && cursor_left <= mid)
			|| (imax < cursor_right))
		{
			tmp[tmp_index] = tab[cursor_left];
			cursor_left++;
		}
		else if ((tab[cursor_right] <= tab[cursor_left] && cursor_right <= imax)
			|| (mid < cursor_left))
		{
			tmp[tmp_index] = tab[cursor_right];
			cursor_right++;
		}
		tmp_index++;
	}
}

static void	merge_sort_recurs(int *tab, int imin, int imax, int *tmp)
{
	int	mid;
	int	i;

	if (!tab || !tmp || imin < 0 || imax < 0 || imax <= imin
		|| is_int_tab_sorted(tab + imin, imax - imin + 1))
		return ;
	mid = (imin + imax) / 2;
	merge_sort_recurs(tab, imin, mid, tmp);
	merge_sort_recurs(tab, mid + 1, imax, tmp);
	sort_sub_table(tab, imin, imax, tmp);
	i = imin;
	while (i <= imax)
	{
		tab[i] = tmp[i];
		i++;
	}
}

void		merge_sort(int *tab, unsigned int size)
{
	int	*tmp;

	if (!tab || size < 2)
		return ;
	if (!(tmp = (int*)malloc(sizeof(int) * size)))
		return ;
	merge_sort_recurs(tab, 0, size - 1, tmp);
	free(tmp);
	return ;
}
