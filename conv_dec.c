/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:36:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 14:43:44 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_sign(t_conv *conv, char *str)
{
	char	*tmp;

	if (conv->sign)
		tmp = ft_strjoin("+", str);
	else
		tmp = ft_strjoin(" ", str);
	free(str);
	return (tmp);
}

void	conv_dec(t_event *ev, t_conv *conv)
{
	intmax_t	in;
	char		*tmp_str;

	if (conv->alt)
		error(1);
	if (!(in = va_arg(ev->ap, intmax_t)))
		error(3);
	if (!(tmp_str = ft_itoa(in)))
		error(2);
	if (in >= 0 && (conv->sign || conv->space))
		tmp_str = handle_sign(conv, tmp_str);
	if (ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	conv->str = tmp_str;
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(conv->str);
}
