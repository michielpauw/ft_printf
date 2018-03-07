/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_func_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:46:27 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/07 17:33:28 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	create_func_arr(t_event *ev)
{
	(ev->func_arr[0]).type = 's';
	(ev->func_arr[0]).f = &conv_string;
	(ev->func_arr[1]).type = 'p';
	(ev->func_arr[1]).f = &conv_pointer;
	(ev->func_arr[2]).type = 'd';
	(ev->func_arr[2]).f = &conv_dec;
	(ev->func_arr[3]).type = 'i';
	(ev->func_arr[3]).f = &conv_dec;
	(ev->func_arr[4]).type = 'o';
	(ev->func_arr[4]).f = &conv_hex_oct;
	(ev->func_arr[5]).type = 'u';
	(ev->func_arr[5]).f = &conv_hex_oct;
	(ev->func_arr[6]).type = 'x';
	(ev->func_arr[6]).f = &conv_hex_oct;
	(ev->func_arr[7]).type = 'c';
	(ev->func_arr[7]).f = &conv_char;
	(ev->func_arr[8]).type = '%';
	(ev->func_arr[8]).f = &conv_percent;
}
