/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/13 19:08:22 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		n;
	int		m;
	void	*p;

	m = 42;
	//printf("{%p}", &n);
//	n = ft_printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
//	n = ft_printf("% BOOOO\n");
//	m = printf("% BOOOO\n");
	n = ft_printf("%");
//	m = printf("%");
//	m = printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
	printf("%d %d\n", m, n);
}
