/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:57:45 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 18:32:11 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_bytes_to_write(wchar_t *tmp_str, t_conv *conv)
{
	int	total;
	int	prev;
	int	index;
	int	to_add;

	if (conv->precision < 0)
		return (0);
	total = 0;
	index = 0;
	while (total <= conv->precision)
	{
		prev = total;
		to_add = get_amount_bytes(*(tmp_str + index), conv);
		total += to_add;
		index++;
	}
	return (prev);
}

size_t	get_amount_bytes(wchar_t c, t_conv *conv)
{
	size_t	length;

	if ((MB_CUR_MAX == 1 || (!conv->upper && conv->len_mod != 'l'))
		&& ((c > 127 && c < 256) || c < 0))
		return (1);
	length = 1;
	while (c /= 2)
		length++;
	if (length < 8)
		return (1);
	return ((length + 3) / 5);
}
