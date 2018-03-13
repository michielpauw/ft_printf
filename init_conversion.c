/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:26:55 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/13 19:06:12 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_conv	new_conv(void)
{
	t_conv	conv;

	conv.type = -1;
	conv.alt = 0;
	conv.zero = 0;
	conv.left = 0;
	conv.sign = 0;
	conv.space = 0;
	conv.min_width = 0;
	conv.precision = 0;
	conv.len_mod = 0;
	conv.length = 0;
	conv.str = 0;
	(conv.types).i = 0;
	return (conv);
}

static int	check_flag(char c, t_conv *conv)
{
	if (c == '#')
		conv->alt = 1;
	else if (c == '0')
		conv->zero = 1;
	else if (c == '-')
		conv->left = 1;
	else if (c == '+')
		conv->sign = 1;
	else if (c == ' ')
		conv->space = 1;
	else
		return (0);
	return (1);
}

static int	check_len_mod(const char *s, int *i, t_conv *conv)
{
	if (ft_strchr("hljz", *(s + *i)))
	{
		if ((*(s + *i) == 'h' || *(s + *i) == 'l')
				&& *(s + *i + 1) == *(s + *i))
		{
			conv->len_mod = *((s + *i) + 22);
			(*i)++;
		}
		else
			conv->len_mod = *(s + *i);
		return (1);
	}
	return (0);
}

static int	check_number(const char *s, int *i, t_conv *conv)
{
	int		num;

	if (ft_isdigit(*(s + *i)))
	{
		num = ft_atoi((char *)(s + *i));
		if (*(s + *i - 1) == '.')
			conv->precision = num;
		else
			conv->min_width = num;
		*i = *i + ft_numlen(num) - 1;
		return (1);
	}
	return (0);
}

int				init_conversion(const char *s, t_event *ev)
{
	char	c;

	ev->cur_conv = new_conv();
	while (1)
	{
		(ev->index)++;
		c = *(s + ev->index);
		if (check_number(s, &(ev->index), &(ev->cur_conv)))
			continue ;
		else if (check_flag(c, &(ev->cur_conv)))
			continue ;
		else if (check_len_mod(s, &(ev->index), &(ev->cur_conv)))
			continue ;
		else if (c == '.')
			continue ;
		else if (convert(ev, &(ev->cur_conv), c))
			return (ev->index);
		else
			return (ev->index);
	}
	return (ev->index);
}
