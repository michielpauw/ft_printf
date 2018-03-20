/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:57:45 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 15:21:00 by mpauw            ###   ########.fr       */
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
		to_add = ft_char_bytes(*(tmp_str + index));
		total += to_add;
		if ((MB_CUR_MAX == 1 || (!conv->upper && conv->len_mod != 'l'))
			&& ((*(tmp_str + index) > 127)
				|| *(tmp_str + index) < 0))
			total -= (to_add - 1);
		index++;
	}
	return (prev);
}
