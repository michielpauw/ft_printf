/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:47:07 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 14:34:26 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(int nb, size_t power)
{
	if (power == 0)
	{
		return (1);
	}
	if (power > 1)
	{
		nb = nb * ft_power(nb, power - 1);
	}
	return (nb);
}