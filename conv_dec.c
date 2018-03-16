/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:36:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:30:07 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_sign(t_conv *conv, char *str)
{
	char	*tmp;

	if (conv->type_sign == '-')
		tmp = ft_strjoin("-", str);
	else if (conv->sign)
	{
		conv->type_sign = '+';
		tmp = ft_strjoin("+", str);
	}
	else
	{
		conv->type_sign = ' ';
		tmp = ft_strjoin(" ", str);
	}
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

static char	*get_initial_str(t_conv *conv)
{
	if (conv->len_mod == 'L')
		return (ft_itoa((conv->types).lli));
	else if (conv->len_mod == 'l')
		return (ft_itoa((conv->types).li));
	else if (conv->len_mod == 'j')
		return (ft_itoa((conv->types).imt));
	else if (conv->len_mod == 'z')
		return (ft_itoa((conv->types).st));
	else if (conv->len_mod == 'H')
		return (ft_itoa((conv->types).sc));
	else if (conv->len_mod == 'h')
		return (ft_itoa((conv->types).si));
	else
		return (ft_itoa((conv->types).i));
}

static char	*conv_neg(char *s, t_conv *conv)
{
	int		len;
	char	*to_return;

	len = ft_strlen(s);
	conv->type_sign = '-';
	if (!(to_return = (char *)malloc(sizeof(char) * len)))
		error(2);
	while (len)
	{
		to_return[len - 1] = s[len];
		len--;
	}
	free(s);
	return (to_return);
}

void		conv_dec(t_event *ev, t_conv *conv)
{
	char	*tmp_str;

	set_len_mod(conv, ev);
	if (!(tmp_str = get_initial_str(conv)))
		error(2);
	if (*tmp_str == '0' && conv->precision < 0)
		*tmp_str = 0;
	if (*tmp_str == '-')
		tmp_str = conv_neg(tmp_str, conv);
	conv->min_width = (conv->zero && (conv->type_sign || conv->sign
				|| conv->space)) ? conv->min_width - 1 : conv->min_width;
	if ((int)ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if ((int)ft_strlen(tmp_str) < conv->min_width && conv->zero)
		tmp_str = handle_min_width(conv, tmp_str);
	if (conv->sign || conv->space || conv->type_sign == '-')
		tmp_str = handle_sign(conv, tmp_str);
	if ((int)ft_strlen(tmp_str) < conv->min_width && !conv->zero)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
	free(tmp_str);
}
