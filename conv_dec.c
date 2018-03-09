/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:36:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 16:58:49 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_sign(t_conv *conv, char *str)
{
	char	*tmp;

	if (conv->sign)
		tmp = ft_strjoin("+", str);
	else
		tmp = ft_strjoin(" ", str);
	free(str);
	return (tmp);
}

static void	set_len_mod(t_conv *conv, t_event *ev)
{
	int	i;

	i = 0;
	while (i < LEN_MOD_AMOUNT)
	{
		if (conv->len_mod == (ev->func_arr_len_mod_dec[i]).type)
		{
			(ev->func_arr_len_mod_hex_oct[i]).f(conv, ev);
			return ;
		}
		i++;
	}
}

void		conv_dec(t_event *ev, t_conv *conv)
{
	char		*tmp_str;

	if (conv->alt)
		error(1);
	set_len_mod(conv, ev);
	if (!(tmp_str = ft_itoa((intmax_t)((conv->types).imt))))
		error(2);
	if (((intmax_t)((conv->types).imt)) >= 0 && (conv->sign || conv->space))
		tmp_str = handle_sign(conv, tmp_str);
	if (ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	conv->str = tmp_str;
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(conv->str);
}
