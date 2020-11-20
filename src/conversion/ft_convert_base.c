/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:56:37 by agardina          #+#    #+#             */
/*   Updated: 2019/04/25 21:25:05 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		else
			i++;
	}
	if (!base[i])
		return (0);
	return (1);
}

static int	err(char *str, char *base)
{
	int i;
	int j;

	if (!str || !str[0] || !base || (int)ft_strlen(base) < 2
		|| (int)ft_strlen(base) > 16)
		return (1);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == '-' || base[j] == '+')
				return (1);
			if (base[j] == base[i] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	i = -1;
	while (str[++i])
		if (!(is_base(base, str[i]) || str[i] == '-' || str[i] == '+'))
			return (1);
	return (0);
}

static int	err_base(char *base)
{
	int i;
	int j;

	if (!base || (int)ft_strlen(base) < 2)
		return (1);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == '-' || base[j] == '+')
				return (1);
			if (base[j] == base[i] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!err(nbr, base_from) && !err_base(base_to))
		return (ft_itoa_base_str(ft_atoi_base(nbr, base_from), base_to));
	return (NULL);
}
