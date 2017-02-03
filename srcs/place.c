/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:08:44 by tjose             #+#    #+#             */
/*   Updated: 2017/02/02 21:12:30 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		place_sign(t_mods *mods, char **ans, int i, char *n)
{
	if (n[0] == '-')
		(*ans)[i++] = '-';
	else if ((mods->flags.hash == o && n[0] != '0')
			|| mods->flags.hash == x || mods->flags.hash == X)
	{
		(*ans)[i++] = '0';
		if (mods->flags.hash == x)
			(*ans)[i++] = 'x';
		if (mods->flags.hash == X)
			(*ans)[i++] = 'X';
	}
	else if (mods->flags.show_sign)
		(*ans)[i++] = '+';
	else if (mods->flags.show_space)
		(*ans)[i++] = ' ';
	return (i);
}

int		place_content(t_mods *mods, char **ans, int i, char *n)
{
	int			precision;
	int			j;

	precision = mods->precision - ft_strlen(n);
	j = 0;
	if (n[0] == '-')
	{
		j++;
		precision++;
	}
	while (precision-- > 0)
		(*ans)[i++] = '0';
	while (n[j])
		(*ans)[i++] = n[j++];
	return (i);
}

int		adjust_i(t_mods *mods, int i, char *n)
{
	if (((mods->flags.show_sign || mods->flags.show_space)
				&& n[0] != '-') || mods->flags.hash == o)
		i--;
	if (mods->precision >= (int)ft_strlen(n) && n[0] == '-')
		i--;
	if (mods->flags.hash == x || mods->flags.hash == X)
		i -= 2;
	return (i);
}

void	place_right(t_mods *mods, char **ans, int size, char *n)
{
	int			i;
	int			bigger;

	i = 0;
	if (mods->precision < 0 && mods->flags.fill_zeroes)
	{
		i = place_sign(mods, ans, i, n);
		if (n[0] == '-')
			n++;
		while (i < size - ft_strlen(n))
			(*ans)[i++] = '0';
	}
	else
	{
		bigger = ((int)ft_strlen(n) > mods->precision) ?
			size - ft_strlen(n) : size - mods->precision;
		while (i < bigger)
			(*ans)[i++] = ' ';
		i = adjust_i(mods, i, n);
		i = place_sign(mods, ans, i, n);
	}
	i = place_content(mods, ans, i, n);
	(*ans)[i] = '\0';
}

void	place_left(t_mods *mods, char **ans, int size, char *n)
{
	int i;

	i = place_sign(mods, ans, 0, n);
	i = place_content(mods, ans, i, n);
	while (i < size)
		(*ans)[i++] = ' ';
	(*ans)[i] = '\0';
}
