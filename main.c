/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/16 15:39:35 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>

int	main(void)
{
	int		n;
	int		m;
	void	*p;
	wint_t	wc[] = {1874, 0};

	setlocale(LC_ALL, "");
	m = 42;
	//printf("{%p}", &n);
//	n = ft_printf("%15S", L"我是一只猫。");
	n = ft_printf("%15.4d", -42);
	printf("\n");
//	m = printf("%lld\n", LLONG_MAX);
	m = printf("%15.4d", -42);
//	m = printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
	printf("\n");
	printf("Fac: %d Own: %d\n", m, n);
}
