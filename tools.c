/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:57:45 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 16:03:49 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_bytes_to_write(wchar_t *tmp_str, t_conv *conv)
{
	int	total;
	int	prev;
	int	index;

	if (conv->precision < 0)
		return (0);
	total = 0;
	index = 0;
	while (total <= conv->precision)
	{
		prev = total;
		total += ft_char_bytes(*(tmp_str + index));
		index++;
	}
	return (prev);
}
