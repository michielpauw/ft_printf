/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 18:32:51 by mpauw            ###   ########.fr       */
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
	int		l;
	int		k;
	void	*p;
	wchar_t	s[4];

//	setlocale(LC_ALL, "");

//	s[0] = 0x53;
//	s[1] = 0x3abc;
//	s[2] = 0x81000;
//	s[3] = '\0';
	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	m = 42;
	//printf("{%p}", &n);
//	k = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
//	k = ft_printf("yo%2C%-12lc et titi %C tyty", 'u', 254, 'a');
//	n = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	n = ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("\n");
//	l = printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
//	l = printf("yo%2C%-12lc et titi %C tyty", 'u', 254, 'a');
	m = printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("\n");
//	printf("Fac: %d Own: %d\n", l, k);
	printf("Fac: %d Own: %d\n", m, n);
}
