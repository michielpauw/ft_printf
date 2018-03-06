/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:10:26 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/06 16:55:16 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char c, size_t length)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	*(str + length) = 0;
	while (length)
	{
		length--;
		*(str + length) = c;
	}
	return (str);
}
