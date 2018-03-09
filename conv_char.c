/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 11:21:25 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	conv_char(t_event *ev, t_conv *conv)
{
	wint_t	in;
	char	*tmp_str;

	if (!(in = va_arg(ev->ap, wint_t)))
		error(3);
	if (conv->alt || conv->zero || conv->sign || conv->space)
		error(1);
	conv->min_width--;
	if (conv->min_width > 0)
		tmp_str = handle_min_width(conv, "");
	if (conv->left)
	{
		ft_putchar(in);
		ft_putstr(tmp_str);
	}
	else
	{
		ft_putstr(tmp_str);
		ft_putchar(in);
	}
	ev->str_len += ((conv->min_width > 0) ? conv->min_width + 1 : 1);
	(ev->index)++;
}
