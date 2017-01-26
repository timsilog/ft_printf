/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:59:19 by tjose             #+#    #+#             */
/*   Updated: 2017/01/23 22:02:43 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_precision(const char *str, t_mods *mods, va_list tags)
{
	int			i;

	i = 0;
	if (str[i] == '.')
	{
		mods->p_found = 1;
		mods->precision = 0;
		if (str[++i] == '*')
		{
			mods->precision = va_arg(tags, int);
			return (2);
		}
		while (ft_isdigit(str[i]))
			mods->precision = mods->precision * 10 + (str[i++] - '0');
	}
	else if (!mods->p_found)
		mods->precision = -1;
	return (i);
}
