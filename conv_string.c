/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:35:14 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:31:04 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	free(tmp_str);
}

void			conv_string(t_event *ev, t_conv *conv)
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
			conv_w_string(ev, conv, tmp_w_str);
			return ;
		}
	}
	handle_little_s(ev, conv, tmp_str);
}
