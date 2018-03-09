/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:54:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 15:39:40 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_char_short(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

static void	len_mod_long(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

static void	len_mod_intmax(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

static void	len_mod_size(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

void		set_len_mod_dec(t_event *ev)
{
	(ev->func_arr_len_mod_dec[0]).type = 'h';
	(ev->func_arr_len_mod_dec[0]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_dec[1]).type = 'H';
	(ev->func_arr_len_mod_dec[1]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_dec[2]).type = 'l';
	(ev->func_arr_len_mod_dec[2]).f = &len_mod_long;
	(ev->func_arr_len_mod_dec[3]).type = 'L';
	(ev->func_arr_len_mod_dec[3]).f = &len_mod_long;
	(ev->func_arr_len_mod_dec[4]).type = 'j';
	(ev->func_arr_len_mod_dec[4]).f = &len_mod_intmax;
	(ev->func_arr_len_mod_dec[5]).type = 'z';
	(ev->func_arr_len_mod_dec[5]).f = &len_mod_size;
}
