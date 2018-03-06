/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:32:03 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/06 16:56:18 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(t_event *ev, t_conv *conv, va_list *ap, char c)
{
	int	i;

	conv->upper = (c >= 'A' && c <= 'Z') ? 1 : 0;
	c = conv->upper ? c + 32 : c;
	conv->type = c;
	i = 0;
	while (i < CONV_AMOUNT)
	{
		if ((ev->func_arr[1]).type = c)
		{
			conv->f = (ev->func_arr[i]).f;
			conv->f(ev, ap);
			return ;
		}
		i++;
	}
	error(0);
}
