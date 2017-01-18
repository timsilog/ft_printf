/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:27:31 by tjose             #+#    #+#             */
/*   Updated: 2017/01/18 15:05:02 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	init_mods(t_mods *mods)
{
	mods->flags.left_justify = 0;
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = no;
	mods->flags.fill_zeroes = 0;
	mods->width = 0;
	mods->precision = 0;
	mods->length = none;
	mods->specifier = '\0';
}

int		find_mods(int i, const char *format, t_mods *mods, va_list tags)
{
	int j;

	j = 1;
	while (j && format[i])
	{
		if ((j = handle_flags(&format[i], mods)))
			i += j;
		else if ((j = handle_width(&format[i], mods, tags)))
			i += j;
		else if ((j = handle_precision(&format[i], mods, tags)))
			i += j;
		else if ((j = handle_length(&format[i], mods)))
			i += j;
		else if (format[i])
		{
			i += handle_specifier(format[i], tags, mods);
			break ;
		}
		else
			j = 0;
	}
	return (i);
}

int		find_handle(va_list tags, t_mods *mods, char *format, int i)
{
	char c;

	c = mods->specifier;
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (handle_number(tags, mods));
	else if (c == 'c')
		return (handle_char(tags, mods));
	else if (c == 's')
		return (handle_str(tags, mods));
	else if (mods->specifier)
		return (handle_nospec(mods));
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
			i++;
			init_mods(&mods);
			i = find_mods(i, format, &mods, tags);
			if (!(j = find_handle(tags, &mods, format, i)))
				return (-1);
			count += j;
		}
		else
		{
			ft_putchar(format[i++]);
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
	va_start(tags, format);
	count = 0;
	if ((count = print_string(format, count, mods, tags)) < 0)
		return (-1);


	return (count);//return num char printed
}
