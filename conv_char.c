/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:53 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 16:03:51 by mpauw            ###   ########.fr       */
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

static int		inv_char(t_conv *conv, t_event *ev, wchar_t in)
{
	if (!conv->upper && conv->len_mod != 'l' && (in > 127 || in < 0))
	{
		ft_putchar(in);
		(ev->index)++;
		(ev->str_len)++;
		return (1);
	}
	else if ((MB_CUR_MAX == 1 && in > 255) || (in < 57344 && in > 55295)
			|| in > 1114111 || in < 0)
	{
		ev->error = 1;
		return (1);
	}
	return (0);
}

void			conv_char(t_event *ev, t_conv *conv)
{
	wchar_t	in;
	char	*tmp_str;
	size_t	bts;

	if (!(tmp_str = (char *)malloc(sizeof(char))))
		error(2);
	*tmp_str = 0;
	in = va_arg(ev->ap, wchar_t);
	if (inv_char(conv, ev, in))
		return ;
	bts = get_amount_bytes(in);
	(conv->min_width) -= bts;
	if (conv->min_width > 0)
		tmp_str = handle_min_width(conv, tmp_str);
	put_char_string(in, tmp_str, conv);
	ev->str_len += (((int)(conv->min_width) > 0) ? conv->min_width + bts : bts);
	(ev->index)++;
}
