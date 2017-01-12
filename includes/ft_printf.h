/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:00:35 by tjose             #+#    #+#             */
/*   Updated: 2017/01/11 15:27:42 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"
# include <stdio.h>///////////

typedef enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}	t_conversion;

typedef struct		s_flags
{
	int				left_justify;
	int				show_sign;
	int				show_space;
	int				hash;
	int				fill_zeroes;
}					t_flags;

typedef struct		s_mods
{
	t_flags			flags;
	int				width;
	int				precision;
	t_conversion	length;
	char			*specifier;
}					t_mods;

int					ft_printf(const char *format, ...);
int					handle_flags(const char *str, t_mods *mods);
int					handle_width(const char *str, t_mods *mods, va_list tags);
int					handle_precision(const char *str,
		t_mods *mods, va_list tags);
int					handle_length(const char *str, t_mods *mods);
int					handle_specifier(char c, va_list tags, t_mods *mods);
int					handle_number(va_list tags, t_mods *mods, char c);
int					is_num(char c);
#endif
