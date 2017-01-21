/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:55 by tjose             #+#    #+#             */
/*   Updated: 2017/01/20 17:10:49 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_cmods(t_mods *mods)
{
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = 0;
	mods->precision = -1;
	mods->length = 0;
}

int			handle_char(va_list tags, t_mods *mods)
{
	char	*ans;
	char	*str_c;
	wint_t	chr;
	int		size;

	// fix all this shit
	if (mods->length == l)
	{
		chr = va_arg(tags,wint_t);
		if (!(str_c = malloc(sizeof(char) * ft_wclen(chr) + 1)))
			return (-1);
	}
	else
	{	
		chr = va_arg(tags, unsigned int);
		str_c[0] = chr;
		str_c[1] = '\0';
	}
	adjust_cmods(mods);
	size = get_size(str_c, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, str_c) :
		place_right(mods, &ans, size, str_c);
	ft_putstr(ans);
	return (size);
}
