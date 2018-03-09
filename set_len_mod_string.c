/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len_mod_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:05:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 15:41:32 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	len_mod_wide_string(t_conv *conv, t_event *ev)
{
	(void)conv;
	(void)ev;
}

void		set_len_mod_string(t_event *ev)
{
	ev->func_len_mod_string = &len_mod_wide_string;
}
