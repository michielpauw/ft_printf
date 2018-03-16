/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:46:27 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:32:13 by mpauw            ###   ########.fr       */
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

void		create_func_arr(t_event *ev)
{
	create_func_arr_conv(ev);
	set_len_mod_dec(ev);
	set_len_mod_hex_oct(ev);
}
