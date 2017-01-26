/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:38:35 by tjose             #+#    #+#             */
/*   Updated: 2017/01/23 21:59:32 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ito_specifier(intmax_t n, t_mods *mods)
{
	char	*ans;
	char	c;
	int		i;

	c = mods->specifier;
	if (c == 'i' || c == 'd' || c == 'u')
		ans = (ft_itoa(n));
	else if (c == 'o')
		ans = (ft_itoabase(n, 8));
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		i = -1;
		ans = ft_itoabase(n, 16);
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
	str_n = ito_specifier(n, mods);
	adjust_nmods(mods, mods->specifier, n);
	size = get_size(str_n, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, str_n) :
		place_right(mods, &ans, size, str_n);
	ft_putstr(ans);
	return (ft_strlen(ans));
}
