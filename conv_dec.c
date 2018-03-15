/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:36:58 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/15 21:05:22 by mpauw            ###   ########.fr       */
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

static char	*conv_str_sign(char *str, char sign)
{
	int	i;
	int	len;
	int	p;

	i = 0;
	p = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (sign && !p  && ((*(str + i + 1) >= '0' && *(str + i + 1) <= '9')
					|| *str == '0'))
		{
			p = 1;
			*(str + i) = sign;
		}
		else if (*(str + i) == sign && p)
			*(str + i) = '0';
		i++;
	}
	return (str);
}

void		conv_dec(t_event *ev, t_conv *conv)
{
	char	*tmp_str;

	if (conv->alt)
		ev->error = 1;
	set_len_mod(conv, ev);
	if (!(tmp_str = get_initial_str(conv)))
		error(2);
	if (*tmp_str == '0' && conv->precision < 0)
		*tmp_str = 0;
	if (((conv->types).i) >= 0 && (conv->sign || conv->space))
		tmp_str = handle_sign(conv, tmp_str);
	if (*tmp_str == '+' || *tmp_str == '-' || *tmp_str == ' ')
		conv->type_sign = *tmp_str;
	if ((int)ft_strlen(tmp_str) - (conv->type_sign > 0) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if ((int)ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	tmp_str = conv_str_sign(tmp_str, conv->type_sign);
	ft_putstr(tmp_str);
}
