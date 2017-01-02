
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>///////////

typedef struct	s_mods
{
	int			flags[5];
	int			width;
	int			precision;
	int			length; // not sure if this is correct
	char		*specifier; // not sure on this either
}				t_mods;

int				ft_printf(const char *format, ...);
int				handle_width(const char *str,
t_mods *mods, va_list tags);
int				handle_precision(const char *str,
t_mods *mods, va_list tags);
int				is_num(char c);
#endif
