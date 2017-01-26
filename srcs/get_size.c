/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:50:20 by tjose             #+#    #+#             */
/*   Updated: 2017/01/23 22:30:17 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Calculates total size of string to malloc/print
** including width, sign, etc.
*/

int				get_size(char *str, t_mods *mods)
{
	int	len;
	int	size;
	int hash_adjust;

	hash_adjust = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (mods->specifier == 'o' && mods->flags.hash)
		hash_adjust++;
	if ((mods->specifier == 'x' || mods->specifier == 'X' ||
				mods->specifier == 'p') && mods->flags.hash)
		hash_adjust += 2;
	if (mods->width > len + hash_adjust && mods->width > mods->precision)
		size = mods->width;
	else
	{
		size = len > mods->precision ?
			len + hash_adjust : mods->precision + hash_adjust;
		if (mods->flags.show_sign || mods->flags.show_space)
			size++;
	}
	return (size);
}
