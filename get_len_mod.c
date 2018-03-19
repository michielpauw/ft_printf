/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:02:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 16:07:11 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_len_mod(t_conv *conv, t_event *ev, char type)
{
	int	i;

	i = 0;
	while (i < LEN_MOD_AMOUNT)
	{
		if (type == 'u' &&
				conv->len_mod == (ev->func_arr_len_mod_hex_oct[i]).type)
		{
			(ev->func_arr_len_mod_hex_oct[i]).f(conv, ev);
			return ;
		}
		else if (type == 'd' &&
				conv->len_mod == (ev->func_arr_len_mod_dec[i]).type)
		{
			(ev->func_arr_len_mod_hex_oct[i]).f(conv, ev);
			return ;
		}
		i++;
	}
}
