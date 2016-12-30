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

void	handle_specifier(char c, va_list tags)
{
	if (c == 'd' || c == 'i')
		handle_decimal(flags);
	/*
	if (c == 'D')
	if (c == 'c')
	if (c == 'C')
	if (c == 's')
	if (c == 'S')
	if (c == 'p')
	if (c == 'o')
	if (c == 'O')
	if (c == 'u')
	if (c == 'U')
	if (c == 'x')
	if (c == 'X')
	*/
}
