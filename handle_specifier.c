/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:43:16 by tjose             #+#    #+#             */
/*   Updated: 2016/12/29 19:48:50 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_specifier(char c, va_list tags, t_mods *mods)
{
	if (c == 'D' || c == 'C' || c == 'O' ||
		c == 'U' || c == 'S')
	{
		mods->length = l;
		c += 32;
	}
	if (c == 'd' || c == 'i')
		return (handle_decimal(tags, mods));
	/*
	if (c == 'c')
	if (c == 's')
	if (c == 'p')
	if (c == 'o') // octal
	if (c == 'u')
	if (c == 'x' || c == 'X') //  hex lower||upper
	*/

	// bonus: eE fF gG aA n
	return (1); //check if this is right
}
