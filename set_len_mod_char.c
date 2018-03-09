/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:01:04 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 15:38:05 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_wide_char(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

void		set_len_mod_char(t_event *ev)
{
	ev->func_len_mod_char = &len_mod_wide_char;
}
