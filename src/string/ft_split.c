/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:14:46 by agardina          #+#    #+#             */
/*   Updated: 2019/04/25 19:37:34 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_sep(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		else
			i++;
	}
	return (0);
}

static int	get_words_nb(char const *s, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_sep(charset, s[i]) && ((i > 0 && is_sep(charset, s[i - 1]))
									|| i == 0))
			count++;
		i++;
	}
	return (count);
}

static void	get_words_info(char const *s, char *charset, t_word *tab)
{
	int i;
	int index;

	i = 0;
	index = -1;
	while (s[i])
	{
		if (!is_sep(charset, s[i]) && ((i > 0 && is_sep(charset, s[i - 1]))
									|| i == 0))
		{
			index++;
			(tab + index)->len = 1;
			(tab + index)->start = i;
		}
		if (i > 0 && !is_sep(charset, s[i]) && !is_sep(charset, s[i - 1]))
			((tab + index)->len)++;
		i++;
	}
}

static void	fill_tab(char const *str, char *substr, t_word word_info)
{
	int i;

	i = 0;
	while (i < word_info.len)
	{
		substr[i] = str[word_info.start + i];
		i++;
	}
	substr[i] = '\0';
}

char		**ft_split(char const *s, char *charset)
{
	char	**tab;
	int		words_nb;
	t_word	*info;
	int		i;

	if (!s || !charset || !charset[0])
		return (NULL);
	words_nb = get_words_nb(s, charset);
	tab = (char**)malloc(sizeof(char*) * (size_t)(words_nb + 1));
	info = (t_word*)malloc(sizeof(t_word) * (size_t)words_nb);
	if (tab == NULL || info == NULL)
		return (NULL);
	get_words_info(s, charset, info);
	i = 0;
	while (i < words_nb)
	{
		if ((tab[i] = (char*)malloc(sizeof(char)
									* (size_t)(info[i].len + 1))) == NULL)
			return (NULL);
		fill_tab(s, tab[i], info[i]);
		i++;
	}
	tab[i] = 0;
	free(info);
	return (tab);
}
