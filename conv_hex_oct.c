/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:37:15 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/07 11:50:29 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_alt(char *str, char type, int upper)
{
	char	*tmp;

	if (type == 'x' && !upper)
		tmp = ft_strjoin(str, "0x");
	else if (type == 'x' && upper)
		tmp = ft_strjoin(str, "0X");
	else if (*str != '0')
		tmp = ft_strjoin(str, "0");
	else
		tmp = str;
	free(str);
	return (tmp);
}

void		conv_hex_oct(t_event *ev, t_conv *conv, va_list *ap)
{
	unsigned long long int	in;
	char					*tmp_str;

	(void)ev;

	in = va_arg(*ap, unsigned long long int);
	if (conv->sign || conv->space)
		error(1);
	if (conv->type == 'x' && !conv->upper)
		tmp_str = ft_int_to_base(in, "0123456789abcdef");
	else if (conv->type == 'x' && conv->upper)
		tmp_str = ft_int_to_base(in, "0123456789ABCDEF");
	else if (conv->type == 'o')
		tmp_str = ft_int_to_base(in, "01234567");
	if (ft_strlen(tmp_str) < conv->precision)
		tmp_str = handle_precision(conv, tmp_str);
	if (conv->alt)
		tmp_str = handle_alt(tmp_str, conv->type, conv->upper);
	if (ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	conv->str = tmp_str;
	conv->length = ft_strlen(tmp_str);
}
