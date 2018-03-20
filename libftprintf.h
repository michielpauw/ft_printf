/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:33:22 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 17:15:31 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define CONV_AMOUNT 9
# define LEN_MOD_AMOUNT 7
# define MAX_BUFF_SIZE 1000

# include "libft/libft.h"
# include <stdarg.h>

typedef union				u_types
{
	int						i;
	signed char				sc;
	short int				si;
	long int				li;
	long long int			lli;
	intmax_t				imt;
	size_t					st;
	unsigned int			ui;
	unsigned char			uc;
	unsigned short int		usi;
	unsigned long int		uli;
	unsigned long long int	ulli;
	uintmax_t				uimt;
	char					c;
	wchar_t					wc;
	char					*cp;
	wchar_t					*wcp;
	void					*p;
}							t_types;

typedef struct				s_func_pair
{
	char					type;
	void					(*f)();
}							t_func_pair;

typedef struct				s_conv
{
	t_types					types;
	int						alt;
	int						zero;
	int						left;
	int						sign;
	int						space;
	int						upper;
	int						min_width;
	int						min_width_o;
	int						precision;
	char					len_mod;
	int						length;
	char					*str;
	char					type;
	char					type_sign;
	int						numeric;
	int						no_putchar;
	void					(*f)();
}							t_conv;

typedef struct				s_event
{
	t_conv					cur_conv;
	int						str_len;
	int						index;
	int						error;
	t_func_pair				func_arr_conv[CONV_AMOUNT];
	t_func_pair				func_arr_len_mod_dec[LEN_MOD_AMOUNT];
	t_func_pair				func_arr_len_mod_hex_oct[LEN_MOD_AMOUNT];
	void					(*func_len_mod_string)();
	void					(*func_len_mod_char)();
	va_list					ap;
	wchar_t					buff[MAX_BUFF_SIZE];
}							t_event;

int							ft_printf(const char *format, ...);
int							init_conversion(const char *s, t_event *ev);
void						create_func_arr(t_event *ev);
int							convert(t_event *ev, t_conv *conv, char c);
void						conv_hex_oct(t_event *ev, t_conv *conv);
void						conv_dec(t_event *ev, t_conv *conv);
void						conv_string(t_event *ev, t_conv *conv);
void						conv_w_string(t_event *ev, t_conv *conv,
		wchar_t *tmp_str);
void						conv_char(t_event *ev, t_conv *conv);
void						conv_percent(t_event *ev, t_conv *conv);
void						conv_pointer(t_event *ev, t_conv *conv);
char						*handle_min_width(t_conv *conv, char *little);
char						*handle_precision(t_conv *conv, char *str);
void						error(int error);
void						set_len_mod_dec(t_event *ev);
void						set_len_mod_hex_oct(t_event *ev);
int							get_bytes_to_write(wchar_t *tmp_str, t_conv *conv);
void						get_len_mod(t_conv *conv, t_event *ev, char type);

#endif
