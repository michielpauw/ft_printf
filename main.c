/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:46 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/19 16:03:52 by mpauw            ###   ########.fr       */
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
	wchar_t	s[4];

	setlocale(LC_ALL, "");

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	m = 42;
	//printf("{%p}", &n);
	n = ft_printf("%---10.5ls", s);
	ft_printf("\n");
	m = printf("%---10.5ls", s);
	printf("\n");
	printf("Fac: %d Own: %d\n", m, n);
}
