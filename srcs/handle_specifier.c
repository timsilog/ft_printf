/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:43:16 by tjose             #+#    #+#             */
/*   Updated: 2017/01/11 15:25:58 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_specifier(char c, va_list tags, t_mods *mods)
{
	if (c == 'D' || c == 'C' || c == 'O' ||
		c == 'U' || c == 'S')
	{
		mods->length = l;
		c += 32; // fix this
	}
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x')
		return (handle_number(tags, mods, c));
	/*
	if (c == 'c') // character
	if (c == 's') // string
	if (c == 'p') // address?
	if (c == 'o') // octal
	if (c == 'u') // unsigned decimal
	if (c == 'x' || c == 'X') //  hex lower||upper
	*/

	// bonus: eE fF gG aA n
	return (1); //check if this is right
}
