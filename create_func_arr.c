/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:46:27 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 13:04:17 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	create_func_arr_conv(t_event *ev)
{
	(ev->func_arr_conv[0]).type = 's';
	(ev->func_arr_conv[0]).f = &conv_string;
	(ev->func_arr_conv[1]).type = 'p';
	(ev->func_arr_conv[1]).f = &conv_pointer;
	(ev->func_arr_conv[2]).type = 'd';
	(ev->func_arr_conv[2]).f = &conv_dec;
	(ev->func_arr_conv[3]).type = 'i';
	(ev->func_arr_conv[3]).f = &conv_dec;
	(ev->func_arr_conv[4]).type = 'o';
	(ev->func_arr_conv[4]).f = &conv_hex_oct;
	(ev->func_arr_conv[5]).type = 'u';
	(ev->func_arr_conv[5]).f = &conv_hex_oct;
	(ev->func_arr_conv[6]).type = 'x';
	(ev->func_arr_conv[6]).f = &conv_hex_oct;
	(ev->func_arr_conv[7]).type = 'c';
	(ev->func_arr_conv[7]).f = &conv_char;
	(ev->func_arr_conv[8]).type = '%';
	(ev->func_arr_conv[8]).f = &conv_percent;
}

static void	create_func_arr_len_mod(t_event *ev)
{
	(ev->func_arr_len_mod[0]).type = 'h';
	(ev->func_arr_len_mod[0]).f = &len_mod_char_short;
	(ev->func_arr_len_mod[1]).type = 'H';
	(ev->func_arr_len_mod[1]).f = &len_mod_char_short;
	(ev->func_arr_len_mod[2]).type = 'l';
	(ev->func_arr_len_mod[2]).f = &len_mod_long;
	(ev->func_arr_len_mod[3]).type = 'L';
	(ev->func_arr_len_mod[3]).f = &len_mod_long;
	(ev->func_arr_len_mod[4]).type = 'j';
	(ev->func_arr_len_mod[4]).f = &len_mod_intmax;
	(ev->func_arr_len_mod[5]).type = 'z';
	(ev->func_arr_len_mod[5]).f = &len_mod_size;
}

void	create_func_arr(t_event *ev)
{
	create_func_arr_conv(ev);
	create_func_arr_len_mod(ev);
}
