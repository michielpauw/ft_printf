/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:35:51 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/15 20:02:15 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
/*
static char	*handle_min_zero(t_conv *conv, char *little)
{
	char	*big;
	size_t	i;

	if (!(big = ft_strset('0', conv->min_width)))
		error(2);
	i = 0;
	while (i < ft_strlen(little))
	{
		*(big + i) = *(little + i);
		i++;
	}
	free(little);
	return (big);
}
*/
void	conv_pointer(t_event *ev, t_conv *conv)
{
	void	*in;
	char	*tmp_str;

	if (conv->alt || conv->sign || conv->space)
		ev->error = 1;
	in = va_arg(ev->ap, void *);
	if (in == NULL)
		tmp_str = ft_strjoin("", "(null)");
	if (!(tmp_str = ft_int_to_base((uintmax_t)in, "0123456789abcdef")))
		error(2);
	tmp_str = ft_strjoin("0x", tmp_str);
	if ((int)ft_strlen(tmp_str) < (int)conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
}
