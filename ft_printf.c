/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:27:31 by tjose             #+#    #+#             */
/*   Updated: 2016/12/27 17:57:07 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	flags;
	int		i;
	
	if (!format) // format[0]?
		return (0);
	va_start(flags, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
		// handle flags
	
		// handle width
	
		// handle .precision
	
		// handle length
	
		// handle specifier
		}
		else
			write(1, &format[i], 1);
	}
}
