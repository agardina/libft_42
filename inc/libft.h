/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:47:18 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 16:40:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "doubly_linked_list.h"
# include "get_next_line.h"
# include "ft_printf_prototypes.h"
# include "int_vectors.h"
# include "list.h"
# include "queue.h"
# include "stack.h"

typedef struct		s_word
{
	int				start;
	int				len;
}					t_word;

typedef enum		e_bool
{
	false,
	true
}					t_bool;

void				bubble_sort(int *tab, unsigned int size);
unsigned long long	ft_abs(long long int a);
int					ft_atoi_base(char *str, char *base);
int					ft_atoi(const char *str);
long				ft_atol(char *str, char **end);
void				ft_bzero(void *s, size_t n);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base_str(int nbr, char *base);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_min(int a, int b);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				**ft_split(char const *s, char *charset);
unsigned int		ft_sqrt(unsigned int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcdup(const char *str, char c, int incl_c,
	int copy_all);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_swap(int *a, int *b);
int					get_next_line(const int fd, char **line);
void				insertion_sort(int *tab, unsigned int size);
char				is_int_tab_sorted(int *tab, unsigned int size);
void				merge_sort(int *tab, unsigned int size);
void				print_int_tab(int *tab, unsigned int size);
void				quicksort(int *tab, unsigned int size);
void				radix_sort(int *tab, unsigned int size);
void				selection_sort(int *tab, unsigned int size);

#endif
