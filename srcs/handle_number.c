/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:38:35 by tjose             #+#    #+#             */
/*   Updated: 2017/01/18 17:41:20 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ito_specifier(intmax_t n, char c)
{
	char	*hex;
	int		i;

	if (c == 'i' || c == 'd' || c == 'u')
		return (ft_itoa(n));
	if (c == 'o')
		return (ft_itoabase(n, 8));
	if (c == 'x' || c == 'X' || c == 'p')
	{
		i = -1;
		hex = ft_itoabase(n, 16);
		while ((c == 'x' || c == 'p') && hex[++i])
		{
			if (hex[i] >= 'A' && hex[i] <= 'Z')
				hex[i] += 32;
		}
		return (hex);
	}
	return (NULL);
}

static void		adjust_nmods(t_mods *mods, char c, intmax_t n)
{
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
	{
		mods->flags.show_sign = 0;
		mods->flags.show_space = 0;
	}
	if (n == 0 && (c == 'x' || c == 'X' || c == 'o' || c == 'p'))
		mods->flags.hash = 0;
	if (mods->flags.hash == yes)
	{
		if (c == 'o')
			mods->flags.hash = o;
		if (c == 'x' || c == 'p')
			mods->flags.hash = x;
		if (c == 'X')
			mods->flags.hash = X;
	}
}

int				handle_number(va_list tags, t_mods *mods)
{
	char		*ans;
	char		*str_n;
	intmax_t	n;
	int			size;

	n = va_arg(tags, intmax_t);
	n = convert_length(n, mods, mods->specifier);
	str_n = ito_specifier(n, mods->specifier);
	adjust_nmods(mods, mods->specifier, n);
	size = get_size(str_n, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, str_n) :
		place_right(mods, &ans, size, str_n);
	ft_putstr(ans);
	return (size);
}
