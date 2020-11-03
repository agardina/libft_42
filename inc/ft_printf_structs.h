/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:32:29 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:32:40 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H

# define FT_PRINTF_STRUCTS_H

typedef struct	s_buf
{
	char		b[FT_PRINTF_BUFF_SIZE + 1];
	char		pad[3];
	int			index;
}				t_buf;

typedef struct	s_conv
{
	t_buf		buf;
	int			width;
	int			prec;
	int			int_size;
	int			f_size;
	int			type;
	int			res;
	char		other_char;
	char		minus;
	char		plus;
	char		zero;
	char		space;
	char		hashtag;
	char		pad[2];
}				t_conv;

typedef union	u_dbl_bits
{
	double		f;
	uint64_t	u;
}				t_dbl_bits;

typedef struct	s_dbl
{
	t_dbl_bits	bits;
	uint64_t	mant;
	int			sign;
	int16_t		expo;
	char		pad[2];
}				t_dbl;

typedef union	u_ldbl_bits
{
	long double	f;
	uint16_t	u[8];
}				t_ldbl_bits;

typedef struct	s_ldbl
{
	t_ldbl_bits	bits;
	uint64_t	mant;
	int			sign;
	int16_t		expo;
	char		pad[2];
}				t_ldbl;

/*
** Chaque case du tableau peut contenir un nombre entre 0 et 2 147 483 647.
** On limite la valeur de chaque case à 999 999 999.
*/

typedef unsigned int	t_bigtab[BIGINT_SIZE];

typedef struct	s_bigint
{
	t_bigtab	tab;
	int			first_int_case;
	int			last_int_case;
	int			first_dec_case;
	int			last_dec_case;
	int			last_digit_rank;
	int			next_figure;
	int			is_long;
}				t_bigint;

typedef struct	s_color
{
	char		*name;
	char		*format;
}				t_color;

#endif
