/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:38:30 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:30:16 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	conv_percent(t_event *ev, t_conv *conv)
{
	char		*tmp_str;

	if (conv->sign || conv->alt)
		ev->error = 1;
	tmp_str = ft_strset('%', 1);
	if ((int)ft_strlen(tmp_str) < conv->min_width)
		tmp_str = handle_min_width(conv, tmp_str);
	ev->str_len += ft_strlen(tmp_str);
	(ev->index)++;
	ft_putstr(tmp_str);
	free(tmp_str);
}
