/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:01:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/05 17:39:58 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	setup_event(t_event *ev)
{
	ev->str_len = 0;
	ev->index = 0;
	create_func_arr(ev);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_event	ev;

	va_start(ap, format);
	setup_event(&ev);
	while (*(format + ev.index))
	{
		if (*(format + ev.index) == '%')
			 ev.index = init_ev.conversion(format, &ap, &ev);
		else
		{
			ft_putchar(*(format + ev.index));
			(ev.index)++;
		}
	}
	va_end(ap);
}
