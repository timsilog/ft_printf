/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:15:06 by tjose             #+#    #+#             */
/*   Updated: 2017/01/23 22:28:46 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	convert_ulength(intmax_t n, t_mods *mods)
{
	if (mods->length == hh)
		return ((unsigned char)n);
	else if (mods->length == h)
		return ((unsigned short)n);
	else if (mods->length == l)
		return ((unsigned long)n);
	else if (mods->length == ll)
		return ((unsigned long long)n);
	else if (mods->length == j)
		return ((uintmax_t)n);
	else if (mods->length == z)
		return ((ssize_t)n);
	else
		return ((unsigned int)n);
}

intmax_t		convert_length(intmax_t n, t_mods *mods, char c)
{
	if (c == 'u' || c == 'x' || c == 'o' || c == 'X' || c == 'p')
		return (convert_ulength(n, mods));
	if (mods->length == hh)
		return ((char)n);
	else if (mods->length == h)
		return ((short)n);
	else if (mods->length == l)
		return ((long)n);
	else if (mods->length == ll)
		return ((long long)n);
	else if (mods->length == j)
		return (n);
	else if (mods->length == z)
		return ((size_t)n);
	else
		return ((int)n);
}
