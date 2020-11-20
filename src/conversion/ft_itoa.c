/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:47:31 by agardina          #+#    #+#             */
/*   Updated: 2019/04/16 18:04:17 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int result;
	int value;

	result = 1;
	if (n < 0)
	{
		value = -n;
		result++;
	}
	else
		value = n;
	while (value / 10)
	{
		result++;
		value = value / 10;
	}
	return (result);
}

static void	fill_str(int n, char *str, int index)
{
	unsigned int	value;

	if (n < 0)
	{
		value = (unsigned int)(-n);
		str[0] = '-';
	}
	else
		value = (unsigned int)n;
	if (value > 9)
		fill_str(value / 10, str, index - 1);
	str[index] = (value % 10) + '0';
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = get_len(n);
	if ((str = (char*)malloc(sizeof(char) * (size_t)(len + 1))) == NULL)
		return (NULL);
	fill_str(n, str, len - 1);
	str[len] = '\0';
	return (str);
}
