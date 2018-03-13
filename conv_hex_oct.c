/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:15 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/13 18:04:00 by mpauw            ###   ########.fr       */
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
	else
		return (((unsigned int)(conv->types).ui));
}

static char	*get_tmp_str(t_conv *conv)
{
	char	*tmp_str;

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

void		conv_hex_oct(t_event *ev, t_conv *conv)
{
	char		*tmp_str;

	if (conv->sign || conv->space)
		ev->error = 1;
	set_len_mod(conv, ev);
	tmp_str = get_tmp_str(conv);
	if (ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (conv->alt)
		tmp_str = handle_alt(tmp_str, conv->type, conv->upper);
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
