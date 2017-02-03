/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:12:45 by tjose             #+#    #+#             */
/*   Updated: 2017/02/02 21:28:52 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_double(const char *str, t_mods *mods, int i)
{
	if (str[i] == 'h')
	{
		if (mods->length == h)
			mods->length = hh;
		else if (mods->length < h)
			mods->length = h;
	}
	else if (str[i] == 'l')
	{
		if (mods->length == l)
			mods->length = ll;
		else if (mods->length < l)
			mods->length = l;
	}
	return (i);
}

static int	is_lc(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int			handle_length(const char *str, t_mods *mods)
{
	int			i;

	i = 0;
	if (str[i] == 'h' || str[i] == 'l')
		i = check_double(str, mods, i);
	else if (str[i] == 'j')
		mods->length = j;
	else if (str[i] == 'z')
		mods->length = z;
	else
		return (0);
	return (1);
}
