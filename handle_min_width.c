/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_min_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:00:02 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/07 11:52:08 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_right(char *big, char *little)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(little))
	{
		*(big + i) = *(little + i);
		i++;
	}
}

static void	handle_left(char *big, char *little, size_t width)
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

char	*handle_min_width(t_conv *conv, char *little)
{
	char	*big;

	if (conv->left || !conv->zero)
	{
		if (!(big = ft_strset(' ', conv->min_width)))
			error(2);
	}
	else
	{
		if (!(big = ft_strset('0', conv->min_width)))
			error(2);
	}
	if (conv->left)
		handle_left(big, little, conv->min_width);
	else
		handle_right(big, little);
	free(little);
	return (big);
}
