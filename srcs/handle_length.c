/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:12:45 by tjose             #+#    #+#             */
/*   Updated: 2017/01/18 14:52:05 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_double(const char *str, t_mods *mods, int i)
{
	if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
		{
			i++;
			mods->length = hh;
		}
		else
			mods->length = h;
	}
	else if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
		{
			i++;
			mods->length = ll;
		}
		else
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
	static int	found;

	i = 0;
	if (!found)
	{
		if (str[i] == 'h' || str[i] == 'l')
			i = check_double(str, mods, i);
		else if (str[i] == 'j')
			mods->length = j;
		else if (str[i] == 'z')
			mods->length = z;
		else
			return (0);
		found = 1;
	}
	else
	{
		while (is_lc(str[i]))
			i++;
		i--;
	}
	return (i + 1);
}
