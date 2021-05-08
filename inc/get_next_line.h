/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:46:14 by agardina          #+#    #+#             */
/*   Updated: 2021/06/27 16:46:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <limits.h>
# define BUFF_SIZE 128
# define GNL_ERR -1
# define GNL_DONE 0
# define GNL_OK 1
# define GNL_CONTINUE 2
# define REMAINDER_EMPTY 0
# define REMAINDER_OK_NO_NEWLINE 1
# define REMAINDER_OK_WITH_NEWLINE 2
# define REMAINDER_ERR 3

int		get_next_line(const int fd, char **line);

#endif
