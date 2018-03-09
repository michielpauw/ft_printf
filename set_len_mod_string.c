/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:05:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 17:02:34 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_wide_string(t_conv *conv, t_event *ev)
{
	if (ft_tolower(conv->len_mod) == 'l')
	{
		if (!((conv->types).wcp = va_arg(ev->ap, wchar_t *)))
			error(3);
	}
	else
	{
		if (!((conv->types).cp = va_arg(ev->ap, char *)))
			error(3);
	}
}

void		set_len_mod_string(t_event *ev)
{
	ev->func_len_mod_string = &len_mod_wide_string;
}
