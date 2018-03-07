#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_AMOUNT 9

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_func_pair
{
	char		type;
	void		(*f)();
}				t_func_pair;

typedef struct	s_conv
{
	int			alt;
	int			zero;
	int			left;
	int			sign;
	int			space;
	int			upper;
	size_t		min_width;
	size_t		precision;
	char		len_mod;
	int			length;
	char		*str;
	char		type;
	void		(*f)();
}				t_conv;

typedef struct	s_event
{
	t_conv		cur_conv;
	int			str_len;
	int			index;
	t_func_pair	func_arr[CONV_AMOUNT];
}				t_event;

int				ft_printf(const char *format, ...);
int				init_conversion(const char *s, va_list *ap, t_event *ev);
void			create_func_arr(t_event *ev);
int				convert(t_event *ev, t_conv *conv, va_list *ap, char c);
void			conv_hex_oct(t_event *ev, t_conv *conv, va_list *ap);
void			conv_dec(t_event *ev, t_conv *conv, va_list *ap);
void			conv_string(t_event *ev, t_conv *conv, va_list *ap);
void			conv_char(t_event *ev, t_conv *conv, va_list *ap);
void			conv_percent(t_event *ev, t_conv *conv, va_list *ap);
void			conv_pointer(t_event *ev, t_conv *conv, va_list *ap);
char			*handle_min_width(t_conv *conv, char *little);
char			*handle_precision(t_conv *conv, char *str);
void			error(int error);

#endif
