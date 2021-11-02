/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:09:50 by agardina          #+#    #+#             */
/*   Updated: 2021/11/02 18:09:52 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_length(long long n)
{
	char	minus;
	int		length;

	if (!n)
		return (1);
	if (n < 0)
		minus = 1;
	else
		minus = 0;
	length = 0;
	while (n)
	{
		length++;
		n /= 10;
	}
	return (length + minus);
}

static void	fill_tab(char *tab, int nb_length, int minus,
						unsigned long long n_abs)
{
	int	i;

	tab[nb_length] = '\0';
	i = nb_length - 1;
	while (minus <= i)
	{
		tab[i] = (char)(n_abs % 10) + '0';
		n_abs /= 10;
		i--;
	}
	if (minus)
		tab[0] = '-';
}

char	*ft_lltoa(long long n)
{
	int					nb_length;
	char				*tab;
	char				minus;
	unsigned long long	n_abs;

	nb_length = get_nb_length(n);
	tab = (char *)malloc(sizeof(char) * (nb_length + 1));
	if (!tab)
		return (NULL);
	if (n < 0)
	{
		minus = 1;
		n_abs = -n;
	}
	else
	{
		minus = 0;
		n_abs = n;
	}
	fill_tab(tab, nb_length, minus, n_abs);
	return (tab);
}
