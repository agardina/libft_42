/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:24:24 by agardina          #+#    #+#             */
/*   Updated: 2019/04/25 21:36:18 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	err_base(char *base)
{
	int i;
	int j;

	if (!base || ft_strlen(base) < 2 || ft_strlen(base) > 16)
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

static int	get_str_len(int nbr, char *base)
{
	unsigned int	i;
	int				count;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	count = 1;
	if (nbr < 0)
	{
		i = (unsigned int)(-nbr);
		if (!(ft_strcmp(base, "0123456789")))
			count++;
	}
	else
		i = (unsigned int)nbr;
	while (i > len_base - 1)
	{
		count++;
		i = i / len_base;
	}
	return (count);
}

static void	convert_nbr(int nbr, char *base, char *str, int index)
{
	unsigned int	value;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	if (nbr < 0)
	{
		value = (unsigned int)(-nbr);
		if (!(ft_strcmp(base, "0123456789")))
			str[0] = '-';
	}
	else
		value = (unsigned int)nbr;
	if (value > len_base - 1)
		convert_nbr((int)(value / len_base), base, str, index - 1);
	str[index] = base[value % len_base];
}

char		*ft_itoa_base_str(int nbr, char *base)
{
	int		str_len;
	char	*str;

	if (!err_base(base))
	{
		str_len = get_str_len(nbr, base);
		if ((str = (char*)malloc(sizeof(char) * ((size_t)str_len + 1))) != NULL)
		{
			convert_nbr(nbr, base, str, str_len - 1);
			str[str_len] = '\0';
			return (str);
		}
	}
	return (NULL);
}
