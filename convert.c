/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:32:03 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/14 16:48:37 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	deal_no_conversion(t_event *ev, t_conv *conv, char c)
{
	char	*tmp_str;
	
	if (!(tmp_str = (char *)malloc(sizeof(char) * 2)))
		error(2);
	*tmp_str = c;
	*(tmp_str + 1) = 0;
	if (conv->min_width > 1)
		tmp_str = handle_min_width(conv, tmp_str);
	ft_putstr(tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
}

int			convert(t_event *ev, t_conv *conv, char c)
{
	int		i;
	char	orig_c;

	conv->upper = (c >= 'A' && c <= 'Z') ? 1 : 0;
	orig_c = c;
	c = conv->upper ? c + 32 : c;
	conv->type = c;
	if (conv->upper && c != 'x')
		conv->len_mod = 'l';
	i = 0;
	while (i < CONV_AMOUNT)
	{
		if ((ev->func_arr_conv[i]).type == c)
		{
			conv->f = (ev->func_arr_conv[i]).f;
			conv->f(ev, conv);
			return (1);
		}
		i++;
	}
	if (conv->min_width)
		deal_no_conversion(ev, conv, orig_c);
	return (0);
}
