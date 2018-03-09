/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:32:03 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 12:58:16 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert(t_event *ev, t_conv *conv, char c)
{
	int	i;

	conv->upper = (c >= 'A' && c <= 'Z') ? 1 : 0;
	c = conv->upper ? c + 32 : c;
	conv->type = c;
	i = 0;
	while (i < CONV_AMOUNT)
	{
		if ((ev->func_arr_conv[i]).type == c)
		{
			conv->f = (ev->func_arr_conv[i]).f;
			conv->f(ev, conv);
			return (1);
		}
		i++;
	}
	return (0);
}
