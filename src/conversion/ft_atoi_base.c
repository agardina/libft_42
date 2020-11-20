/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:41:53 by agardina          #+#    #+#             */
/*   Updated: 2019/04/25 16:41:58 by agardina         ###   ########.fr       */
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

static int	get_index(char *base, char c)
{
	int i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int result;

	if (err(str, base))
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_base(base, str[i]) && str[i])
	{
		result = (result * (int)ft_strlen(base)) + get_index(base, str[i]);
		i++;
	}
	return (sign * result);
}
