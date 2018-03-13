/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/13 20:24:45 by mpauw            ###   ########.fr       */
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
	wint_t	wc;

	setlocale(LC_ALL, "");
	m = 42;
	wc = L'猫';
	//printf("{%p}", &n);
	n = ft_printf("Mine: %S", NULL);
	printf("\n");
	m = printf("The other: %S", NULL);
//	m = printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
	printf("\n");
	printf("Fac: %d Own: %d\n", m, n);
}
