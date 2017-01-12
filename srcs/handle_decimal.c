/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:46:28 by tjose             #+#    #+#             */
/*   Updated: 2017/01/11 20:22:31 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		place_sign(t_mods *mods, char **ans, int i, char *n)
{
	if (*n == '-')
		(*ans)[i++] = '-';
	else if (mods->flags.show_sign)
		(*ans)[i++] = '+';
	else if (mods->flags.show_space)
		(*ans)[i++] = ' ';
	return (i);
}

static int		place_number(t_mods *mods, char **ans, int i, char *n)
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
	i = place_sign(mods, ans, i, n);
	while (precision-- > 0)
		(*ans)[i++] = '0';
	while (n[j])
		(*ans)[i++] = n[j++];
	return (i);
}

static void		place_right(t_mods *mods, char **ans, int size, char *n)
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
			size - (int)ft_strlen(n) : size - mods->precision;
		while (i < bigger)
			(*ans)[i++] = ' ';
	}
	if ((mods->flags.show_sign || mods->flags.show_space) && n[0] != '-')
		i--;
	i = place_number(mods, ans, i, n);
	(*ans)[i] = '\0';
}

static void		place_left(t_mods *mods, char **ans, int size, char *n)
{
	int i;

	i = place_number(mods, ans, 0, n);
	while (i < size)
		(*ans)[i++] = ' ';
	(*ans)[i] = '\0';
}

static intmax_t	convert_length(intmax_t n, t_mods *mods)
{
	if (mods->length == hh)
		return ((char)n);
	else if (mods->length == h)
		return ((short)n);
	else if (mods->length == l)
		return ((long)n);
	else if (mods->length == ll)
		return ((long long)n);
	else if (mods->length == j)
		return (n);
	else if (mods->length == z)
		return ((size_t)n);
	else
		return ((int)n);
}

char			*ito_specifier(intmax_t n, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_itoa(n));
	//if (c == 'o')
	//	return (ft_atoibase(n, 8));
	/*if (c == 'u')
	 *	do unsigned int
	 *if (c == 'x')
	 *	do hexidecimal */

}

int				get_size(char *str_n, t_mods *mods)
{
	int	len;
	int	size;

	len = ft_strlen(str_n);
	if (str_n[0] == '-')
		len--;
	if (mods->width > len && mods->width > mods->precision)
		size = mods->width;
	else
	{
		size = len > mods->precision ? len : mods->precision;
		if (mods->flags.show_sign || mods->flags.show_space)
			size++;
	}
	return (size);
}

int				handle_number(va_list tags, t_mods *mods, char c)
{
	char		*ans;
	char		*str_n;
	intmax_t	n;
	int			size;

	n = va_arg(tags, intmax_t);
	n = convert_length(n, mods);
	str_n = ito_specifier(n, c);
	size = get_size(str_n, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, str_n) :
		place_right(mods, &ans, size, str_n);
	ft_putstr(ans);
	return (size);
}
