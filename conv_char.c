/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:30:01 by mpauw            ###   ########.fr       */
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

static void		put_char_string(wchar_t in, char *tmp_str, t_conv *conv)
{
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
	free(tmp_str);
}

void			conv_char(t_event *ev, t_conv *conv)
{
	wchar_t	in;
	char	*tmp_str;

	if (!(tmp_str = (char *)malloc(sizeof(char))))
		error(2);
	*tmp_str = 0;
	in = va_arg(ev->ap, wchar_t);
	if (!conv->upper && conv->len_mod != 'l' && in > 127)
	{
		ft_putchar('?');
		(ev->index)++;
		(ev->str_len)++;
		return ;
	}
	(conv->min_width)--;
	if (conv->min_width > 0)
		tmp_str = handle_min_width(conv, tmp_str);
	put_char_string(in, tmp_str, conv);
	ev->str_len += (((int)(conv->min_width) > 0) ? conv->min_width + 1 :
			get_amount_bytes(in));
	(ev->index)++;
}
