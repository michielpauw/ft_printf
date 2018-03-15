/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:35:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/15 21:40:16 by mpauw            ###   ########.fr       */
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

static void		handle_big_s(t_event *ev, t_conv *conv, wchar_t *tmp_str)
{
	int	bytes;
	int	i;

	if (conv->precision < 0)
		*tmp_str = 0;
	bytes = 0;
	i = 0;
	while (*(tmp_str + i))
		bytes += get_amount_bytes(*(tmp_str + i++));
	if (bytes > conv->precision && conv->precision > 0)
		*(tmp_str + conv->precision) = 0;
	if (bytes < conv->min_width)
		tmp_str = handle_min_width_big_s(conv, tmp_str, bytes);
	else
		conv->min_width = bytes;
	i = 0;
	while (*tmp_str && i < conv->min_width)
	{
		i += get_amount_bytes(*(tmp_str));
		ft_putchar(*(tmp_str++));
	}
	ev->str_len += (bytes > conv->min_width) ? bytes : conv->min_width;
	(ev->index)++;
}

static void		handle_little_s(t_event *ev, t_conv *conv, char *tmp_str)
{
	if (tmp_str == NULL && !((tmp_str = va_arg(ev->ap, char *))))
		tmp_str = ft_strdup("(null)");
	else
		tmp_str = ft_strdup(tmp_str);
	if (conv->precision < 0)
		*tmp_str = 0;
	if ((int)ft_strlen(tmp_str) > conv->precision && conv->precision > 0)
		*(tmp_str + conv->precision) = 0;
	if ((int)ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}

void		conv_string(t_event *ev, t_conv *conv)
{
	wchar_t	*tmp_w_str;
	char	*tmp_str;

	tmp_str = NULL;
	if (conv->alt)
		ev->error = 1;
	if (ft_tolower(conv->len_mod) == 'l' || conv->type == 'S')
	{
		if (!(tmp_w_str = va_arg(ev->ap, wchar_t *)))
			tmp_str = ft_strdup("(null)");
		else
		{
			handle_big_s(ev, conv, tmp_w_str);
			return ;
		}
	}
	handle_little_s(ev, conv, tmp_str);
}
