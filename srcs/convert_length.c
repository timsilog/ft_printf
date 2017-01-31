/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:15:06 by tjose             #+#    #+#             */
/*   Updated: 2017/01/31 14:13:57 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ito_specifier(intmax_t n, t_mods *mods)
{
	char	*ans;
	char	c;
	int		i;

	c = mods->specifier;
	if (c == 'i' || c == 'd')
		ans = (ft_itoa(n));
	else
		return (NULL);
	if (n == 0 && mods->precision == 0)
		ans[0] = '\0';
	return (ans);
}

static char *ito_uspecifier(uintmax_t n, t_mods *mods)
{
	char	*ans;
	char	c;
	int		i;

	c = mods->specifier;
	if (c == 'u')
		ans = ft_uitoabase(n, 10);
	else if (c == 'o')
		ans = ft_uitoabase(n, 8);
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		i = -1;
		ans = ft_uitoabase(n, 16);
		while ((c == 'x' || c == 'p') && ans[++i])
		{
			if (ans[i] >= 'A' && ans[i] <= 'Z')
				ans[i] += 32;
		}
	}
	else
		return (NULL);
	if (n == 0 && mods->precision == 0)
		ans[0] = '\0';
	return (ans);
}

char		*convert_ulength(va_list tags, t_mods *mods, char c)
{
	uintmax_t n;

	n = va_arg(tags, uintmax_t);
	adjust_nmods(mods, c, n);
	if (mods->length == hh)
		return (ito_uspecifier((unsigned char)n, mods));
	else if (mods->length == h)
		return (ito_uspecifier((unsigned short)n, mods));
	else if (mods->length == l)
		return (ito_uspecifier((unsigned long)n, mods));
	else if (mods->length == ll)
		return (ito_uspecifier((unsigned long long)n, mods));
	else if (mods->length == j)
		return (ito_uspecifier((uintmax_t)n, mods));
	else if (mods->length == z)
		return (ito_uspecifier((ssize_t)n, mods));
	else
		return (ito_uspecifier((unsigned int)n, mods));
}

char		*convert_length(va_list tags, t_mods *mods, char c)
{
	intmax_t n;

	n = va_arg(tags, intmax_t);
	adjust_nmods(mods, c, n);
	if (mods->length == hh)
		return (ito_specifier((char)n, mods));
	else if (mods->length == h)
		return (ito_specifier((short)n, mods));
	else if (mods->length == l)
		return (ito_specifier((long)n, mods));
	else if (mods->length == ll)
		return (ito_specifier((long long)n, mods));
	else if (mods->length == j)
		return (ito_specifier(n, mods));
	else if (mods->length == z)
		return (ito_specifier((size_t)n, mods));
	else
		return (ito_specifier((int)n, mods));
}
