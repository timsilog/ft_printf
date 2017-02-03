/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:55 by tjose             #+#    #+#             */
/*   Updated: 2017/02/02 20:05:46 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		adjust_cmods(t_mods *mods, char *str_c)
{
	if (!str_c[0] && mods->width > 0)
		mods->width--;
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = 0;
	mods->precision = -1;
	mods->length = 0;
}

static char		*just_one(va_list tags)
{
	char	chr;
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	chr = va_arg(tags, int);
	//if (ft_isascii(chr))
		str[0] = chr;
	//else
	//	str[0] = '\0';
	str[1] = '\0';
	return (&str[0]);
}

static char		*go_wide(va_list tags)
{
	wchar_t	chr;
	char	*str;
	int		i;

	i = 0;
	chr = va_arg(tags, wchar_t);
	if (!(str = malloc(sizeof(char) * ft_wclen(chr) + 1)))
		return (NULL);
	ft_wctomb(str, chr);
	return (str);
}

int				handle_char(va_list tags, t_mods *mods)
{
	char	*ans;
	char	*str_c;
	char	chr;
	int		size;

	/*if (mods->length == l)
	{
		str_c = go_wide(tags);
		if (!str_c)
			return (-1);
	}
	else*/
		str_c = just_one(tags);
	adjust_cmods(mods, str_c);
	size = get_size(str_c, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, str_c) :
		place_right(mods, &ans, size, str_c);
	ft_putstr(ans);
	if (!str_c[0])
		size++;
	return (size);
}
