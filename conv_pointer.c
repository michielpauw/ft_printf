/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:35:51 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 14:43:40 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	conv_pointer(t_event *ev, t_conv *conv)
{
	void	*in;
	char	*tmp_str;

	if (conv->alt || conv->sign || conv->zero || conv->left || conv->space)
		error(1);
	if (!(in = va_arg(ev->ap, void *)))
		error(3);
	if (!(tmp_str = ft_int_to_base((uintmax_t)in,
					"0123456789abcdef")))
		error(2);
	conv->str = tmp_str;
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(conv->str);
}
