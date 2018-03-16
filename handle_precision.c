/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:27:38 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 17:32:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*handle_string(t_conv *conv, char *str)
{
	char	*to_return;

	if (!(to_return = (char *)malloc(sizeof(char) * (conv->precision + 1))))
		error(2);
	to_return = ft_strncpy(to_return, str, conv->precision);
	*(to_return + conv->precision) = 0;
	free(str);
	return (to_return);
}

char		*handle_precision(t_conv *conv, char *str)
{
	char	*to_return;
	size_t	i;
	size_t	j;

	if (conv->type == 's')
		return (handle_string(conv, str));
	if (!(to_return = ft_strset('0', conv->precision)))
		error(2);
	i = conv->precision;
	j = ft_strlen(str);
	while (j)
	{
		i--;
		j--;
		*(to_return + i) = *(str + j);
	}
	free(str);
	return (to_return);
}
