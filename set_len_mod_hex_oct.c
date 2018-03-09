/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_hex_oct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:44:05 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 16:29:33 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_char_short(t_conv *conv, t_event *ev)
{
	if (!(conv->len_mod))
	{
		if (!((conv->types).ui = va_arg(ev->ap, unsigned int)))
			error(3);
	}
	else if (conv->len_mod == 'H')
	{
		if (!((conv->types).uc = va_arg(ev->ap, int)))
			error(3);
	}
	else
	{
		if (!((conv->types).usi = va_arg(ev->ap, int)))
			error(3);
	}
}

static void	len_mod_long(t_conv *conv, t_event *ev)
{
	if (conv->len_mod == 'L')
	{
		if (!((conv->types).ulli = va_arg(ev->ap, unsigned long long int)))
			error(3);
	}
	else
	{
		if (!((conv->types).uli = va_arg(ev->ap, unsigned long int)))
			error(3);
	}
}

static void	len_mod_intmax(t_conv *conv, t_event *ev)
{
	if (!((conv->types).uimt = va_arg(ev->ap, uintmax_t)))
		error(3);
}

static void	len_mod_size(t_conv *conv, t_event *ev)
{
	if (!((conv->types).st = va_arg(ev->ap, size_t)))
		error(3);
}

void		set_len_mod_hex_oct(t_event *ev)
{
	(ev->func_arr_len_mod_hex_oct[0]).type = 0;
	(ev->func_arr_len_mod_hex_oct[0]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_hex_oct[1]).type = 'h';
	(ev->func_arr_len_mod_hex_oct[1]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_hex_oct[2]).type = 'H';
	(ev->func_arr_len_mod_hex_oct[2]).f = &len_mod_char_short;
	(ev->func_arr_len_mod_hex_oct[3]).type = 'l';
	(ev->func_arr_len_mod_hex_oct[3]).f = &len_mod_long;
	(ev->func_arr_len_mod_hex_oct[4]).type = 'L';
	(ev->func_arr_len_mod_hex_oct[4]).f = &len_mod_long;
	(ev->func_arr_len_mod_hex_oct[5]).type = 'j';
	(ev->func_arr_len_mod_hex_oct[5]).f = &len_mod_intmax;
	(ev->func_arr_len_mod_hex_oct[6]).type = 'z';
	(ev->func_arr_len_mod_hex_oct[6]).f = &len_mod_size;
}
