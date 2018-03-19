/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:15 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 16:06:39 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char						*handle_alt(char *str, t_conv *conv)
{
	char	*tmp;

	if (!(*str) && conv->type == 'x')
		return (str);
	if (conv->type == 'x' && !conv->upper)
	{
		tmp = ft_strjoin("0x", str);
		free(str);
	}
	else if (conv->type == 'x' && conv->upper)
	{
		tmp = ft_strjoin("0X", str);
		free(str);
	}
	else if (*str != '0')
	{
		tmp = ft_strjoin("0", str);
		free(str);
	}
	else
		tmp = str;
	return (tmp);
}

static unsigned long long int	get_in(t_conv *conv)
{
	if (conv->len_mod == 'L')
		return (((unsigned long long int)(conv->types).ulli));
	else if (conv->len_mod == 'l')
		return (((unsigned long int)(conv->types).uli));
	else if (conv->len_mod == 'j')
		return (((uintmax_t)(conv->types).uimt));
	else if (conv->len_mod == 'z')
		return (((size_t)(conv->types).st));
	else if (conv->len_mod == 'H')
		return (((unsigned char)(conv->types).uc));
	else if (conv->len_mod == 'h')
		return (((unsigned short int)(conv->types).usi));
	else
		return (((unsigned int)(conv->types).ui));
}

static char						*get_tmp_str(t_conv *conv)
{
	char					*tmp_str;

	if (conv->type == 'x' && !conv->upper)
	{
		if (!(tmp_str = ft_int_to_base(get_in(conv), "0123456789abcdef")))
			error(2);
	}
	else if (conv->type == 'x' && conv->upper)
	{
		if (!(tmp_str = ft_int_to_base(get_in(conv), "0123456789ABCDEF")))
			error(2);
	}
	else if (conv->type == 'u')
	{
		if (!(tmp_str = ft_int_to_base(get_in(conv), "0123456789")))
			error(2);
	}
	else
	{
		if (!(tmp_str = ft_int_to_base(get_in(conv), "01234567")))
			error(2);
	}
	return (tmp_str);
}

static char						*min_width_alt(t_conv *conv, char *tmp_str,
		int zero)
{
	int	bool_width_prec;

	bool_width_prec = (conv->min_width <= conv->precision &&
			conv->precision != 0) ? 1 : 0;
	if (conv->alt && conv->zero && !zero && conv->precision == 0)
		bool_width_prec = 1;
	if (conv->alt && conv->zero && !zero)
		conv->min_width -= (conv->type == 'x' && bool_width_prec) ? 2 : 0;
	if ((int)ft_strlen(tmp_str) < conv->min_width && conv->type == 'x'
			&& bool_width_prec)
		tmp_str = handle_min_width(conv, tmp_str);
	if (conv->alt && conv->zero && !zero)
		tmp_str = handle_alt(tmp_str, conv);
	if ((int)ft_strlen(tmp_str) < conv->min_width &&
			(conv->type != 'x' || !bool_width_prec))
		tmp_str = handle_min_width(conv, tmp_str);
	return (tmp_str);
}

void							conv_hex_oct(t_event *ev, t_conv *conv)
{
	char	*tmp_str;
	int		zero;

	get_len_mod(conv, ev, 'u');
	tmp_str = get_tmp_str(conv);
	if (*tmp_str == '0' && conv->precision < 0)
		*tmp_str = 0;
	zero = (*tmp_str == '0') ? 1 : 0;
	if ((int)ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (conv->alt && !conv->zero && !zero)
		tmp_str = handle_alt(tmp_str, conv);
	tmp_str = min_width_alt(conv, tmp_str, zero);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
	free(tmp_str);
}
