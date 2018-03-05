#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_AMOUNT 15

# include "libftprintf.h"
# include <stdarg.h>

typedef struct	s_func_pair
{
	char		type;
	int			(*f)();
}				t_func_pair;

typedef struct	s_conv
{
	int			alt;
	int			zero;
	int			left;
	int			sign;
	int			space;
	int			min_width;
	int			precision;
	char		len_mod;
	int			length;
	char		*str;
}				t_conv;

typedef struct	s_event
{
	t_conv		conv;
	int			str_len;
	int			index;
	t_func_pair	func_arr[CONV_AMOUNT];
}				t_event

int		ft_printf(const char *format, ...);
int		init_conversion(const char *s, va_list ap, t_event *ev);
void	handle_conversion(t_conv *conv, t_event *ev, va_list ap);

#endif
