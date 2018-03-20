/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:26:55 by mpauw             #+#    #+#             */
/*   Updated: 2018/03/20 17:46:32 by mpauw            ###   ########.fr       */
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
	conv.type_sign = 0;
	(conv.types).i = 0;
	conv.no_putchar = 0;
	return (conv);
}

static int		check_flag(char c, t_conv *conv, const char *s, int *i)
{
	if (c == '#')
		conv->alt = 1;
	else if (c == '0')
	{
		if (*(s + *i - 1) == '.')
			return (1);
		conv->zero = 1;
	}
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

static int		check_len_mod(const char *s, int *i, t_conv *conv)
{
	char	c;

	if (ft_strchr("hljz", *(s + *i)))
	{
		if ((*(s + *i) == 'h' || *(s + *i) == 'l')
				&& *(s + *i + 1) == *(s + *i))
		{
			conv->upper = 1;
			c = *(s + *i) - 32;
			(*i)++;
		}
		else
			c = *(s + *i);
		if (conv->len_mod)
		{
			if (ft_strchr("HhzjlL", c) > ft_strchr("HhzjlL", conv->len_mod))
				conv->len_mod = c;
		}
		else
			conv->len_mod = c;
		return (1);
	}
	return (0);
}

static int		check_number(const char *s, int *i, t_conv *conv)
{
	int		num;

	if (ft_isdigit(*(s + *i)) && (*(s + *i) != '0'))
	{
		num = ft_atoi((char *)(s + *i));
		if (*(s + *i - 1) == '.')
			conv->precision = (num == 0) ? -2 : num;
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
		if (!c)
			return (ev->index);
		else if (check_number(s, &(ev->index), &(ev->cur_conv)))
			continue ;
		else if (check_flag(c, &(ev->cur_conv), s, &(ev->index)))
			continue ;
		else if (check_len_mod(s, &(ev->index), &(ev->cur_conv)))
			continue ;
		else if (c == '.')
		{
			(ev->cur_conv).precision = -1;
			continue ;
		}
		else if (convert(ev, &(ev->cur_conv), c))
			return (ev->index);
		else
			return (ev->index);
	}
}
