/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:35:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/13 20:24:42 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static wchar_t	*handle_min_width_big_s(t_conv *conv, wchar_t *tmp_str,
		size_t len)
{
	wchar_t	*big;
	size_t	i;

	if (!(big = (wchar_t *)malloc(sizeof(wchar_t) * (conv->min_width + 1))))
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

static void	handle_big_s(t_event *ev, t_conv *conv)
{
	wchar_t	*tmp_str;
	size_t	len;
	size_t	bytes;

	bytes = 0;
	if (!((tmp_str = va_arg(ev->ap, wchar_t *))))
		tmp_str = (wchar_t *)ft_strdup("(null)");
	len = 0;
	while (*(tmp_str + len))
		len++;
	if (len < conv->precision)
		*(tmp_str + conv->precision) = 0;
	len = 0;
	while (*(tmp_str + len))
	{
		bytes += get_amount_bytes(*(tmp_str + len));
		len++;
	}
	if (len < conv->min_width)
	{
		tmp_str = handle_min_width_big_s(conv, tmp_str, len);
		len = conv->min_width;
	}
	while (*tmp_str)
		ft_putchar(*(tmp_str++));
	ev->str_len += bytes;
	(ev->index)++;
}

void		conv_string(t_event *ev, t_conv *conv)
{
	char	*tmp_str;
	size_t	len;

	if (conv->alt || conv->sign || conv->space || conv->zero)
		ev->error = 1;
	if (ft_tolower(conv->len_mod) == 'l' || conv->type == 'S')
	{
		handle_big_s(ev, conv);
		return ;
	}
	if (!((tmp_str = va_arg(ev->ap, char *))))
		tmp_str = ft_strdup("(null)");
	if (ft_strlen(tmp_str) < conv->precision)
		*(tmp_str + conv->precision) = 0;
	if ((len = ft_strlen(tmp_str)) < conv->min_width)
		tmp_str = handle_min_width_small_s(conv, tmp_str, len);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
