/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:35:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/14 17:34:09 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static wchar_t	*set_w_string(size_t size, char c)
{
	wchar_t	*big;
	size_t	i;

	if (!(big = (wchar_t *)malloc(sizeof(char) * (size + 1))))
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
		size_t len)
{
	wchar_t	*big;
	size_t	i;

	big = set_w_string(conv->min_width, ' ');
	i = 0;
	if (conv->left)
	{
		while (i < len)
		{
			*(big + i) = *(tmp_str + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(big - len + i) = *(tmp_str + i);
			i++;
		}
	}
	return (big);
}
/*
static char		*handle_min_width_small_s(t_conv *conv, char *tmp_str,
		size_t len)
{
	char	*big;
	size_t	i;

	if (!(big = (char *)malloc(sizeof(char) * (conv->min_width + 1))))
		error(2);
	*(big + conv->min_width) = 0;
	i = 0;
	if (conv->left)
	{
		while (i < len)
		{
			*(big + i) = *(tmp_str + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(big + conv->min_width - len + i) = *(tmp_str + i);
			i++;
		}
	}
	return (big);
}
*/
static size_t	get_amount_bytes(wchar_t *s)
{
	size_t	bytes;
	size_t	length;
	wchar_t	c;

	bytes = 0;
	while (*s)
	{
		c = *s;
		length = 1;
		while (c /= 2)
			length++;
		if (length < 8)
			bytes += 1;
		else
			bytes += ((length + 3) / 5);
		s++;
	}
	return (bytes);
}

void			handle_big_s(t_event *ev, t_conv *conv, wchar_t *tmp_str)
{
	size_t	bytes;

	bytes = 0;
	bytes += get_amount_bytes(tmp_str);
	//if (bytes < conv->precision)
	//	*(tmp_str + conv->precision) = 0;
	if (bytes < conv->min_width)
		tmp_str = handle_min_width_big_s(conv, tmp_str, bytes);
	while (*tmp_str)
		ft_putchar(*(tmp_str++));
	ev->str_len += (bytes > conv->min_width) ? bytes : conv->min_width;
	(ev->index)++;
}

void		conv_string(t_event *ev, t_conv *conv)
{
	char	*tmp_str;
	wchar_t	*tmp_w_str;

	if (conv->alt || conv->sign || conv->space || conv->zero)
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
	else if (!((tmp_str = va_arg(ev->ap, char *))))
		tmp_str = ft_strdup("(null)");
	if (ft_strlen(tmp_str) < conv->precision)
		*(tmp_str + conv->precision) = 0;
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
