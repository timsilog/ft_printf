/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:12:45 by tjose             #+#    #+#             */
/*   Updated: 2017/01/10 16:38:49 by tjose            ###   ########.fr       */
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
	return (i + 1);
}

int			handle_length(const char *str, t_mods *mods)
{
	int i;

	i = 0;
	if (str[i] == 'h' || str[i] == 'l')
		return (check_double(str, mods, i));
	else if (str[i] == 'j')
		mods->length = j;
	else if (str[i] == 'z')
		mods->length = z;
	else
		return (0);
	return (i + 1);
}
