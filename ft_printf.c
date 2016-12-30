/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:27:31 by tjose             #+#    #+#             */
/*   Updated: 2016/12/29 19:48:48 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flags(char c, int flag[5])
{
	int i;

	i = -1;
	while (++i < 5)
		flag[i] = 0;
	if (c == '-')
		flag[0]++; // left justify (uses width)
	if (c == '+')
		flag[1]++; // show sign
	if (c == ' ')
		flag[2]++; // show space if no sign
	if (c == '#')
		flag[3]++; /* precede o, x, X with 0, 0x, 0X
					  force e, E, f, F to contain decimal */
	if (c == '0')
		flag[4]++; // fills leftover width with zeroes
}

int		ft_printf(const char *format, ...)
{
	va_list	tags;
	int		i;
	int		flag[5];
	
	if (!format) // format[0]?
		return (0);
	va_start(tags, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
		// handle flags
			handle_flags(format[i], flag);
	
		// handle width
	
		// handle .precision
	
		// handle length
	
		// handle specifier
			handle_specifer(format[i], flags);
		}
		else
			write(1, &format[i], 1);
	}
}
