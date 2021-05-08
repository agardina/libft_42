/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:46:28 by agardina          #+#    #+#             */
/*   Updated: 2021/06/27 16:46:30 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_all_and_return(int code, char **line, char **remainder)
{
	free(*line);
	*line = NULL;
	free(*remainder);
	*remainder = NULL;
	return (code);
}

static int	deal_with_remainder(char **line, char **remainder)
{
	char	*nl;

	if (ft_str_is_empty(*remainder))
		return (REMAINDER_EMPTY);
	nl = ft_strchr(*remainder, '\n');
	*line = ft_copy_str_until_char_excl(*remainder, '\n', 1);
	if (!*line)
		return (REMAINDER_ERR);
	if (ft_trim_str_after_char_excl(remainder, '\n', 1))
		return (REMAINDER_ERR);
	if (nl)
		return (REMAINDER_OK_WITH_NEWLINE);
	return (REMAINDER_OK_NO_NEWLINE);
}

static int	read_fd(char *buffer, char **line, int fd)
{
	int	ret;

	ret = read(fd, buffer, BUFF_SIZE);
	if (ret < 0)
		return (GNL_ERR);
	buffer[ret] = '\0';
	if (ret > 0 && !ft_strlen(buffer))
		return (GNL_ERR);
	else if (ret == 0)
		return (GNL_DONE);
	if (!ft_str_is_empty(*line))
		ft_strcat_realloc(line, buffer);
	else
		*line = ft_strdup(buffer);
	if (!*line)
		return (GNL_ERR);
	return (GNL_CONTINUE);
}

static int	check_newline(char *buffer, char **remainder, char **line)
{
	if (ft_str_is_empty(buffer))
		return (GNL_DONE);
	if (ft_strchr(buffer, '\n'))
	{
		*remainder = ft_strdup(ft_strchr(buffer, '\n') + 1);
		if (!*remainder)
			return (GNL_ERR);
		ft_trim_str_until_char_excl(line, '\n', 0);
		if (!*line)
			return (GNL_ERR);
		return (GNL_OK);
	}
	return (GNL_CONTINUE);
}

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*remainder;
	int			ret;

	if (!line || BUFF_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (GNL_ERR);
	*line = NULL;
	ret = deal_with_remainder(line, &remainder);
	if (ret == REMAINDER_ERR)
		return (free_all_and_return(GNL_ERR, line, &remainder));
	else if (ret == REMAINDER_OK_WITH_NEWLINE)
		return (GNL_OK);
	while (1)
	{
		ret = read_fd(buffer, line, fd);
		if (ret == GNL_ERR || (ret == GNL_DONE && ft_str_is_empty(*line)))
			return (free_all_and_return(ret, line, &remainder));
		ret = check_newline(buffer, &remainder, line);
		if (ret == GNL_ERR)
			return (free_all_and_return(ret, line, &remainder));
		if (ret == GNL_OK || ret == GNL_DONE)
			break ;
	}
	return (GNL_OK);
}
