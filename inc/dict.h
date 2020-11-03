/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:19:49 by agardina          #+#    #+#             */
/*   Updated: 2020/11/03 18:20:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H

# define DICT_H
# define DICT_SIZE 10000

typedef struct			s_dict_entry
{
	struct s_dict_entry	*next;
	char				*key;
	char				*value;
}						t_dict_entry;

typedef struct			s_dict
{
	t_dict_entry		**entries;
}						t_dict;

t_dict					*dict_create(void);
void					dict_dump(t_dict *dict);
char					*dict_get(t_dict *dict, char *key);
char					dict_set(t_dict *dict, char *key, char *value);
unsigned int			hash(const char *key);

#endif
