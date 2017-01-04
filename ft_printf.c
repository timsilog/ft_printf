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


void	init_mods(t_mods *mods)
{
	mods->flags.left_justify = 0;
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = 0;
	mods->flags.fill_zeroes = 0;
	mods->width = 0;
	mods->precision = 0;
	mods->length = 0;
}

int		print_string(const char *format, int count, t_mods mods)
{
	int i;
	int j;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
		// handle flags. bonus: * $ L '
			if ((j = handle_flags(&format[++i], &mods)) < 0)
				return (-1);
			else
				i += j;
	
		// handle width
			if ((j = handle_width(&format[i], &mods, tags)) < 0)
				return (-1);
			else
				i += j;
	
		// handle .precision
			if ((j = handle_precision(&format[i], &mods, tags)) < 0)
				return (-1);
			else
				i += j;
	
		// handle length
			if ((j = handle_length(&format[i], &mods)))
				i += j;
	
		// handle specifier
			//handle_specifer(format[i], flags);
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	tags;
	int		i;
	int		j;
	int		count;
	t_mods	mods;
	
	if (!format) // format[0]?
		return (0);
	init_mods(&mods);
	va_start(tags, format);
	count = 0;
	if (!(count = print_string(format, count, mods)))
		return (-1);

	printf("\nflags.left_justify = %d\nflags.show_sign = %d\nflags.show_space = %d\nflags.hash = %d\nflags.fill_zeroes = %d\nwidth = %d\nprecision = %d\nlength = %d of {hh, h, l, ll, j, z}\n",mods.flags.left_justify,mods.flags.show_sign,mods.flags.show_space,mods.flags.hash,mods.flags.fill_zeroes,mods.width,mods.precision, mods.length);
	return (count);//return num char printed
}
