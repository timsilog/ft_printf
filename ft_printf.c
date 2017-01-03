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

int		handle_flags(const char *str, t_mods *mods)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
		|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '-')
			mods->flags.left_justify++; // left justify (uses width)
		else if (str[i] == '+')
			mods->flags.show_sign++; // show sign
		else if (str[i] == ' ')
			mods->flags.show_space++; // show space if no sign
		else if (str[i] == '#')
			mods->flags.hash++; /* precede o, x, X with 0, 0x, 0X
								force e, E, f, F to contain decimal */
		else if (str[i] == '0')
			mods->flags.fill_zeroes++; // fills leftover width with zeroes
		i++;
	}
	return (i);
}

void	init_mods(t_mods *mods)
{
	(mods->flags).left_justify = 0;
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = 0;
	mods->flags.fill_zeroes = 0;
	mods->width = 0;
	mods->precision = 0;
	mods->length = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list	tags;
	int		i;
	int		j;
	t_mods	mods;
	
	if (!format) // format[0]?
		return (0);
	init_mods(&mods);
	va_start(tags, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
		// handle flags
			if ((j = handle_flags(&format[++i], &mods)))
				i += j;
	
		// handle width
			if ((j = handle_width(&format[i], &mods, tags)))
				i += j;
	
		// handle .precision
			if ((j = handle_precision(&format[i], &mods, tags)))
				i += j;
	
		// handle length
	
		// handle specifier
			//handle_specifer(format[i], flags);
		}
		else
			write(1, &format[i++], 1);
	}
	printf("\nflags.left_justify = %d\nflags.show_sign = %d\nflags.show_space = %d\nflags.hash = %d\nflags.fill_zeroes = %d\nwidth = %d\nprecision = %d\n",mods.flags.left_justify,mods.flags.show_sign,mods.flags.show_space,mods.flags.hash,mods.flags.fill_zeroes,mods.width,mods.precision);
	return (0);//return num char printed
}
