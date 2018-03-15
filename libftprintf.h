#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_AMOUNT 9
# define LEN_MOD_AMOUNT 7

# include "libft/libft.h"
# include <stdarg.h>

typedef union				u_types
{
	int						i;
	signed char				sc;
	short int				si;
	long int				li;
	long long int			lli;
	intmax_t				imt;
	size_t					st;
	unsigned int			ui;
	unsigned char			uc;
	unsigned short int		usi;
	unsigned long int		uli;
	unsigned long long int	ulli;
	uintmax_t				uimt;
	char					c;
	wchar_t					wc;
	char					*cp;
	wchar_t					*wcp;
	void					*p;
}							t_types;

typedef struct				s_func_pair
{
	char					type;
	void					(*f)();
}							t_func_pair;

typedef struct				s_conv
{
	t_types					types;
	int						alt;
	int						zero;
	int						left;
	int						sign;
	int						space;
	int						upper;
	int						min_width;
	int						precision;
	char					len_mod;
	int						length;
	char					*str;
	char					type;
	char					type_sign;
	void					(*f)();
}							t_conv;

typedef struct				s_event
{
	t_conv					cur_conv;
	int						str_len;
	int						index;
	int						error;
	t_func_pair				func_arr_conv[CONV_AMOUNT];
	t_func_pair				func_arr_len_mod_dec[LEN_MOD_AMOUNT];
	t_func_pair				func_arr_len_mod_hex_oct[LEN_MOD_AMOUNT];
	void					(*func_len_mod_string)();
	void					(*func_len_mod_char)();
	va_list					ap;
}							t_event;

int							ft_printf(const char *format, ...);
int							init_conversion(const char *s, t_event *ev);
void						create_func_arr(t_event *ev);
int							convert(t_event *ev, t_conv *conv, char c);
void						conv_hex_oct(t_event *ev, t_conv *conv);
void						conv_dec(t_event *ev, t_conv *conv);
void						conv_string(t_event *ev, t_conv *conv);
void						conv_char(t_event *ev, t_conv *conv);
void						conv_percent(t_event *ev, t_conv *conv);
void						conv_pointer(t_event *ev, t_conv *conv);
char						*handle_min_width(t_conv *conv, char *little);
char						*handle_precision(t_conv *conv, char *str);
void						error(int error);
void						set_len_mod_dec(t_event *ev);
void						set_len_mod_hex_oct(t_event *ev);
void						set_len_mod_string(t_event *ev);
void						set_len_mod_char(t_event *ev);

#endif
