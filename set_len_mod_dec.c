/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:54:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:33:07 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_char_short(t_conv *conv, t_event *ev)
{
	int	set;

	set = 0;
	if (!(conv->len_mod))
		(conv->types).i = va_arg(ev->ap, int);
	else if (conv->len_mod == 'H')
		(conv->types).c = va_arg(ev->ap, int);
	else
		(conv->types).si = va_arg(ev->ap, int);
}

static void	len_mod_long(t_conv *conv, t_event *ev)
{
	if (conv->len_mod == 'L')
	{
		(conv->types).lli = va_arg(ev->ap, long long int);
	}
	else
		(conv->types).li = va_arg(ev->ap, long int);
}

static void	len_mod_intmax(t_conv *conv, t_event *ev)
{
	(conv->types).imt = va_arg(ev->ap, intmax_t);
}

static void	len_mod_size(t_conv *conv, t_event *ev)
{
	(conv->types).st = va_arg(ev->ap, size_t);
}

void		set_len_mod_dec(t_event *ev)
{
	(ev->func_arr_len_mod_dec[0]).type = 0;
	(ev->func_arr_len_mod_dec[0]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_dec[1]).type = 'h';
	(ev->func_arr_len_mod_dec[1]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_dec[2]).type = 'H';
	(ev->func_arr_len_mod_dec[2]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_dec[3]).type = 'l';
	(ev->func_arr_len_mod_dec[3]).f = &len_mod_long;
	(ev->func_arr_len_mod_dec[4]).type = 'L';
	(ev->func_arr_len_mod_dec[4]).f = &len_mod_long;
	(ev->func_arr_len_mod_dec[5]).type = 'j';
	(ev->func_arr_len_mod_dec[5]).f = &len_mod_intmax;
	(ev->func_arr_len_mod_dec[6]).type = 'z';
	(ev->func_arr_len_mod_dec[6]).f = &len_mod_size;
}
