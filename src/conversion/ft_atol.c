/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:45:58 by agardina          #+#    #+#             */
/*   Updated: 2020/05/14 11:47:20 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str, char **end)
{
	unsigned int	i;
	long			res;
	long			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (!((res <= 2147483647l) || (res == 2147483648l && sign == -1)))
			return (0);
	}
	*end = str + i;
	return (res * sign);
}
