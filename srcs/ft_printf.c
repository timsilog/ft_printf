/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:27:31 by tjose             #+#    #+#             */
/*   Updated: 2017/01/10 17:00:08 by tjose            ###   ########.fr       */
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

int		print_string(const char *format, int count,
t_mods mods, va_list tags)
{
	int i;
	int j;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{ 
			/* j will be the number of characters read in order
			 * to increment i by that amount. if j is ever -1 
			 * then we return due to an error 
			 */
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
			if ((j = handle_specifier(format[i], tags, &mods)) < 0)
				return (-1);
			else
			{
				count += j;
				i++;
			}
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
	////////////////////////////////////////////////////////////
	char *a[7] = {"none", "hh", "h", "l", "ll", "j", "z"};
	printf("\n.........................\nleft_justify = %s\t.\nshow_sign = %s\t\t.\nshow_space = %s\t\t.\nhash = %s\t\t.\nfill_zeroes = %s\t.\nwidth = %d\t\t.\nprecision = %d\t\t.\nlength = %s\t\t.\n.........................",mods.flags.left_justify ? "yes" : "no",mods.flags.show_sign?"yes":"no",mods.flags.show_space?"yes":"no",mods.flags.hash?"yes":"no",mods.flags.fill_zeroes?"yes":"no",mods.width,mods.precision, a[mods.length]);////////////////////////////////////
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list	tags;
	int		count;
	t_mods	mods;
	
	if (!format) // format[0]?
		return (0);
	init_mods(&mods);
	va_start(tags, format);
	count = 0;
	if (!(count = print_string(format, count, mods, tags)))
		return (-1);


	return (count);//return num char printed
}
