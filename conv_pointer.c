/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:35:51 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 14:38:42 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	conv_pointer(t_event *ev, t_conv *conv)
{
	void	*in;
	char	*tmp_str;

	if (conv->alt)
		ev->error = 1;
	if (conv->precision < 0)
		tmp_str = ft_strset(0, 1);
	else
	{
		in = va_arg(ev->ap, void *);
		if (in == NULL)
			tmp_str = ft_strjoin("", "(null)");
		if (!(tmp_str = ft_int_to_base((uintmax_t)in, "0123456789abcdef")))
			error(2);
	}
	if ((int)ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	tmp_str = ft_strjoin("0x", tmp_str);
	if ((int)ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
