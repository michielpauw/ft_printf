/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:56:12 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/06 13:29:31 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_to_base(unsigned long long nbr, const char *base_to)
{
	char	*conv;
	size_t	len_new;
	size_t	len_to;
	int		i;

	len_to = ft_strlen(base_to);
	len_new = 1;
	while ((unsigned long long)ft_power(len_to, len_new) < nbr)
		len_new++;
	if (!(conv = (char *)malloc(sizeof(char) * (len_new + 1 + i))))
		return (NULL);
	while (len_new)
	{
		*(conv + i) = *(base_to + ((nbr % ft_power(len_to, len_new)) /
				ft_power(len_to, len_new - 1)));
		i++;
		len_new--;
	}
	*(conv + i) = 0;
	return (conv);
}
