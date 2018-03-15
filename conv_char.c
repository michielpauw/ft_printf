/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/15 20:05:43 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_amount_bytes(wchar_t c)
{
	size_t	length;

	length = 1;
	while (c /= 2)
		length++;
	if (length < 8)
		return (1);
	return ((length + 3) / 5);
}

void	conv_char(t_event *ev, t_conv *conv)
{
	wchar_t	in;
	char	*tmp_str;

	if (!(tmp_str = (char *)malloc(sizeof(char))))
		error(2);
	*tmp_str = 0;
	in = va_arg(ev->ap, wchar_t);
	(conv->min_width)--;
	if (((int)conv->min_width) > 0)
		tmp_str = handle_min_width(conv, tmp_str);
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
	ev->str_len += (((int)(conv->min_width) > 0) ? conv->min_width + 1 :
			get_amount_bytes(in));
	(ev->index)++;
}
