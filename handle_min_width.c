/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_min_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:00:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 18:32:04 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_left(char *big, char *little)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(little))
	{
		*(big + i) = *(little + i);
		i++;
	}
}

static void	handle_right(char *big, char *little, size_t width)
{
	size_t	i;
	size_t	j;

	i = width;
	j = ft_strlen(little);
	while (j)
	{
		i--;
		j--;
		*(big + i) = *(little + j);
	}
}

char		*handle_min_width(t_conv *conv, char *little)
{
	char	*big;

	if (conv->left || !conv->zero || (conv->precision > 0 && conv->type != '%')
			|| (conv->precision == -1 && conv->numeric == 1))
	{
		if (!(big = ft_strset(' ', conv->min_width)))
			error(2);
	}
	else
	{
		if (!(big = ft_strset('0', conv->min_width)))
			error(2);
	}
	if (conv->left || (conv->type == 'p' && conv->zero))
		handle_left(big, little);
	else
		handle_right(big, little, conv->min_width);
	free(little);
	return (big);
}
