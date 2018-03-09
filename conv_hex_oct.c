/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:15 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/09 17:33:14 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_alt(char *str, char type, int upper)
{
	char	*tmp;

	if (type == 'x' && !upper)
		tmp = ft_strjoin("0x", str);
	else if (type == 'x' && upper)
		tmp = ft_strjoin("0X", str);
	else if (*str != '0')
		tmp = ft_strjoin("0", str);
	else
		tmp = str;
	free(str);
	return (tmp);
}

static void	set_len_mod(t_conv *conv, t_event *ev)
{
	int	i;

	i = 0;
	while (i < LEN_MOD_AMOUNT)
	{
		if (conv->len_mod == (ev->func_arr_len_mod_hex_oct[i]).type)
		{
			(ev->func_arr_len_mod_hex_oct[i]).f(conv, ev);
			return ;
		}
		i++;
	}
}

void		conv_hex_oct(t_event *ev, t_conv *conv)
{
	char		*tmp_str;

	if (conv->sign || conv->space)
		error(1);
	set_len_mod(conv, ev);
	if (conv->type == 'x' && !conv->upper)
		tmp_str = ft_int_to_base((uintmax_t)((conv->types).uimt),
				"0123456789abcdef");
	else if (conv->type == 'x' && conv->upper)
		tmp_str = ft_int_to_base((uintmax_t)((conv->types).uimt),
				"0123456789ABCDEF");
	else if (conv->type == 'u')
		tmp_str = ft_int_to_base((uintmax_t)((conv->types).uimt), "0123456789");
	else if (conv->type == 'o')
		tmp_str = ft_int_to_base((uintmax_t)((conv->types).uimt), "01234567");
	if (ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (conv->alt)
		tmp_str = handle_alt(tmp_str, conv->type, conv->upper);
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	conv->str = tmp_str;
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(conv->str);
}
