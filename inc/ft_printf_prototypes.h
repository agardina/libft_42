/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prototypes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:07:34 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:33:11 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PROTOTYPES_H

# define FT_PRINTF_PROTOTYPES_H
# define FT_PRINTF_BUFF_SIZE 512
# define SIZE_HH 1
# define SIZE_H 2
# define SIZE_L 3
# define SIZE_LL 4
# define SIZE_LF 1
# define TYPE_C 0
# define TYPE_D 1
# define TYPE_F 2
# define TYPE_LF 3
# define TYPE_O 4
# define TYPE_P 5
# define TYPE_S 6
# define TYPE_U 7
# define TYPE_X 8
# define TYPE_BIG_X 9
# define TYPE_B 10
# define BIGINT_SIZE 1000
# define CELL_LIMIT 999999999
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf_structs.h"

int					print_c(va_list ap, t_conv *conv);
int					print_d(va_list ap, t_conv *conv);
int					print_f(va_list ap, t_conv *conv);
int					print_lf(va_list ap, t_conv *conv);
int					print_o(va_list ap, t_conv *conv);
int					print_p(va_list ap, t_conv *conv);
int					print_s(va_list ap, t_conv *conv);
int					print_u(va_list ap, t_conv *conv);
int					print_x(va_list ap, t_conv *conv);
int					print_big_x(va_list ap, t_conv *conv);
int					print_b(va_list ap, t_conv *conv);

int					color_found(char **str, t_color color, t_conv *conv);
long long int		convert_s_number(va_list ap, t_conv *conv);
unsigned long long	convert_u_number(va_list ap, t_conv *conv);
int					ft_printf(const char *restrict format, ...);
void				ft_putnbr_base_buf(t_conv *conv, unsigned long long nb,
		char *base);
void				ft_putnbr_buf(t_conv *conv, unsigned long long nb);
void				get_c_type(char **str, t_conv *conv);
int					get_color(char **str, t_conv *conv);
int					get_convert_len(unsigned long long nb, t_conv *conv);
void				get_conv_info(va_list ap, char **str, t_conv *conv);
void				get_length(char **str, t_conv *conv);
void				get_prec(va_list ap, char **str, t_conv *conv);
void				get_type(char **str, t_conv *conv);
int					get_uint_len(unsigned long long nb);
void				get_width(va_list ap, char **str, t_conv *conv);
void				init_conv(t_conv *conv);
int					is_conv_char(char c);
int					is_lm(char c);
int					is_type(char c);
void				print_buffer(t_buf *buf);
int					print_format_string(va_list ap, t_conv *conv, char **str);
int					print_int(va_list ap, t_buf buf, t_conv *conv);
void				print_no_format(t_conv *conv, char **str);
void				print_padding(t_conv *conv, int len);
void				print_s_prefix(long long nb, t_conv *conv);
int					print_string(va_list ap, t_buf *buf, t_conv *conv);
void				print_u_prefix(unsigned long long nb, t_conv *conv);
int					putc_no_format(t_conv *conv, char c);
void				puts_no_format(t_conv *conv, char *str, int len);
void				put_spaces(int nb, t_conv *conv);
void				put_zeros(int nb, t_conv *conv);
void				set_prio_flags(t_conv *conv);

void				add_bigints(t_bigint *big, t_bigint *to_add);
void				create_unit(t_bigint *big, unsigned int size, int expo);
void				cut_tab(t_bigint *big);
int					deal_inf_nan_dbl(t_conv *conv, t_dbl dbl);
int					deal_inf_nan_ldbl(t_conv *conv, t_ldbl ldbl);
void				div_bigint_by_2(t_bigint *big);
unsigned int		div_by_10(unsigned int nb, int power);
void				filling_zeros(t_conv *conv, unsigned int nb);
void				get_bigint_info(t_bigint *big, int16_t expo, int prec);
void				get_d_info(t_dbl *dbl, t_conv *conv, unsigned int *len);
int					get_first_int_case(int16_t expo, t_bigint *big);
int					get_last_dec_case(int16_t expo, int prec, t_bigint *big);
int					get_last_digit_rank(int16_t expo, int prec, t_bigint *big);
void				get_ld_info(t_ldbl *ldbl, t_conv *conv, unsigned int *len);
int					get_next_figure(t_bigint *big);
void				get_prec_to_add(t_bigint *to_add, int index);
void				init_bigint(t_bigint *tab);
void				mult_bigint_by_2(t_bigint *big);
int					only_nine(unsigned int nb);
int					print_big_dbl(int16_t expo, t_conv *conv, t_bigint *big);
void				print_dec_part(t_bigint *big, int prec, int16_t expo,
		t_conv *conv);
void				print_first_dec(unsigned int nb, int *prec, int *i,
		t_conv *conv);
void				print_first_int_digits(t_bigint *big, int *res,
		t_conv *conv, int *int_part_start);
void				print_f_prefix(t_conv *conv, int sign);
int					print_inf_nan(t_conv *conv, char *str);
int					print_int_part(t_bigint *big, int16_t expo, int prec,
		t_conv *conv);
int					print_small_dbl(int16_t expo, t_conv *conv, t_bigint *big);
int					put_dbl_buffer(int16_t expo, t_conv *conv, t_bigint *big);
int					put_ldbl_buffer(int16_t expo, t_bigint *big, t_conv *conv);
void				round_up_bigint(t_bigint *big,
		unsigned int last_dec_to_print);
void				stock_dbl(t_dbl *dbl, t_bigint *big, int prec,
		unsigned int *len);
void				stock_ldbl(t_ldbl *ldbl, t_bigint *big, int prec,
		unsigned int *len);
void				store_big_dbl(t_dbl dbl, t_bigint *big);
void				store_big_ldbl(t_ldbl ldbl, t_bigint *big);
void				store_small_dbl(t_dbl dbl, t_bigint *big);
void				store_small_ldbl(t_ldbl ldbl, t_bigint *big);

#endif
