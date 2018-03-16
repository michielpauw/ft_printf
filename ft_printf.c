/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:45:43 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:31:16 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		error(int error)
{
	if (error == 2)
		ft_putstr_fd("Error whilst allocating memory\n", 2);
	exit(1);
}

static void	setup_event(t_event *ev, va_list ap)
{
	ev->str_len = 0;
	ev->index = 0;
	ev->error = 0;
	create_func_arr(ev);
	va_copy(ev->ap, ap);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_event	ev;

	va_start(ap, format);
	setup_event(&ev, ap);
	while (*(format + ev.index))
	{
		if (*(format + ev.index) == '%')
			ev.index = init_conversion(format, &ev);
		else
		{
			ft_putchar(*(format + ev.index));
			(ev.index)++;
			(ev.str_len)++;
		}
		if (ev.error)
			return (-1);
	}
	va_end(ap);
	return (ev.str_len);
}
