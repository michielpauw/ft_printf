/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_w_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:51:50 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 15:58:38 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static wchar_t	*set_w_string(int size, wchar_t c)
{
	wchar_t	*big;
	int		i;

	if (!(big = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		error(2);
	*(big + size) = 0;
	i = 0;
	while (i < size)
	{
		*(big + i) = c;
		i++;
	}
	return (big);
}

static wchar_t	*handle_min_width_big_s(t_conv *conv, wchar_t *tmp_str,
		int len)
{
	wchar_t	*big;
	int		i;

	if (conv->left || !conv->zero)
		big = set_w_string(conv->min_width, L' ');
	else
		big = set_w_string(conv->min_width, L'0');
	i = 0;
	if (conv->left)
	{
		while (i < len && *(tmp_str + i))
		{
			*(big + i) = *(tmp_str + i);
			i++;
		}
	}
	else
	{
		while (i < len && *(tmp_str + i))
		{
			*(big + conv->min_width - len + i) = *(tmp_str + i);
			i++;
		}
	}
	return (big);
}

static void		write_w_string(t_event *ev, t_conv *conv, wchar_t *tmp_str)
{
	int	i;

	i = 0;
	while (i < conv->min_width)
	{
		i += ft_char_bytes(*(tmp_str));
		ft_putchar(*(tmp_str++));
	}
	ev->str_len += i;
	(ev->index)++;
}

static int		inv_char(t_conv *conv, t_event *ev, wchar_t in)
{
	if (!conv->upper && conv->len_mod != 'l' && (in > 127 || in < 0))
	{
		ft_putchar(-1);
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

void			conv_w_string(t_event *ev, t_conv *conv, wchar_t *tmp_str)
{
	int		bytes;
	int		i;
	wchar_t	*to_free;

	bytes = 0;
	i = -1;
	to_free = NULL;
	while (tmp_str[++i])
	{
		if (inv_char(conv, ev, tmp_str[i]))
			return ;
		bytes += ft_char_bytes(*(tmp_str + i));
	}
	if (conv->precision < 0 || (bytes > conv->precision && conv->precision > 0))
		bytes = get_bytes_to_write(tmp_str, conv);
	if (bytes < conv->min_width)
	{
		tmp_str = handle_min_width_big_s(conv, tmp_str, bytes);
		to_free = tmp_str;
	}
	else
		conv->min_width = bytes;
	write_w_string(ev, conv, tmp_str);
	if (to_free)
		free(to_free);
}
