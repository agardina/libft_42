/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:03:42 by agardina          #+#    #+#             */
/*   Updated: 2020/10/30 15:44:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_and_return(char *str, int ret)
{
	ft_strdel(&str);
	return (ret);
}

static int	read_and_stock(const int fd, char **stock)
{
	char	*buffer;
	char	*tmp;
	int		ret;

	if (!(buffer = (char*)malloc(sizeof(char) * (GNL_BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, GNL_BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((int)ft_strlen(buffer) != ret)
			return (free_and_return(buffer, -1));
		if (!*stock && !(*stock = ft_strdup("")))
			return (free_and_return(buffer, -1));
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, buffer)))
		{
			ft_strdel(&tmp);
			return (free_and_return(buffer, -1));
		}
		ft_strdel(&tmp);
		if (ft_strchr(*stock, '\n'))
			break ;
	}
	return (free_and_return(buffer, ret));
}

int			get_next_line(const int fd, char **line)
{
	static char	*stock[OPEN_MAX];
	char		*tmp;
	char		*end;
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || !line || GNL_BUFF_SIZE < 1)
		return (-1);
	ret = read_and_stock(fd, &stock[fd]);
	if (ret == -1 || (ret == 0 && (!stock[fd] || !stock[fd][0])))
		return (ret);
	if (!(*line = ft_strcdup(stock[fd], '\n', 0, 1)))
		return (-1);
	end = ft_strchr(stock[fd], '\n');
	tmp = stock[fd];
	if (!(stock[fd] = end ? ft_strdup(end + 1) : ft_strdup("")))
		return (free_and_return(tmp, -1));
	ft_strdel(&tmp);
	return (1);
}
