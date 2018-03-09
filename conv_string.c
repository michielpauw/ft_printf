/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:35:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 17:42:45 by mpauw            ###   ########.fr       */
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

static wchar_t	*handle_min_width_small_s(t_conv *conv, char *tmp_str,
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

static void	handle_big_s(t_event *ev, t_conv *conv)
{
	wchar_t	*tmp_str;
	size_t	len;

	if (!((tmp_str = va_arg(ev->ap, wchar_t *))))
		error(3);
	len = 0;
	while (*(tmp_str + len))
		len++;
	if (len < conv->precision)
		*(tmp_str + conv->precision) = 0;
	len = 0;
	while (*(tmp_str + len))
		len++;
	if (len < conv->min_width)
	{
		tmp_str = handle_min_width_big_s(conv, tmp_str, len);
		len = conv->min_width;
	}
	while (*tmp_str)
		ft_putchar(*(tmp_str++));
	ev->str_len += len;
	(ev->index)++;
}

void		conv_string(t_event *ev, t_conv *conv)
{
	char	*tmp_str;

	if (conv->alt || conv->sign || conv->space || conv->zero)
		error(1);
	if (ft_tolower(conv->len_mod) == 'l' || conv->type == 'S')
	{
		handle_big_s(ev, conv);
		return ;
	}
	if (!((tmp_str = va_arg(ev->ap, char *))))
		error(3);
	if (ft_strlen(tmp_str) < conv->precision)
		*(tmp_str + conv->precision) = 0;
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width_small_s(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
