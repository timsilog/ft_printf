/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:53:41 by tjose             #+#    #+#             */
/*   Updated: 2017/01/30 17:17:52 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_smods(t_mods *mods)
{
	mods->flags.show_sign = 0;
	mods->flags.show_space = 0;
	mods->flags.hash = 0;
	mods->length = 0;
}

static char	*adjust_mbstr(char *str, int precision)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if ((j = is_mb(&str[i])))
			i += j;
		else
		{
			str[i] = '\0';
			break ;
		}
	}
	return (str);
}

static char	*adjust_str(t_mods *mods, char *old_str)
{
	char	*new_str;
	int		i;

	if (mods->precision > -1)
	{
		i = -1;
		if (!(new_str = malloc(sizeof(char) * mods->precision + 1)))
			return (NULL);
		while (++i < mods->precision)
			new_str[i] = old_str[i];
		new_str[i] = '\0';
		free(old_str);
		new_str = adjust_mbstr(new_str, mods->precision);
		mods->precision = -1;
		return (new_str);
	}
	else
		return (old_str);
}

static int	get_strsize(char *str, t_mods *mods)
{
	int len;
	int size;

	len = 0;
	while (str[len])
		len++;
	if (mods->width < len)
		size = len;
	else
		size = mods->width;
	return (size);
}

int			handle_str(va_list tags, t_mods *mods)
{
	char	*ans;
	char	*new_str;
	wchar_t	*old_str;
	int		size;

	old_str = va_arg(tags, wchar_t*);
	if (!(new_str = malloc(sizeof(char) * ft_wcslen(old_str) + 1)))
		return (-1);
	if (mods->length == l)
		ft_wcstombs(new_str, old_str, sizeof(new_str));
	else
		ft_strcpy(new_str, (char*)old_str);
	if (!(new_str = adjust_str(mods, new_str)))
		return (-1);
	adjust_smods(mods);
	size = get_strsize(new_str, mods);
	if (!(ans = malloc(sizeof(char) * size + 1)))
		return (-1);
	mods->flags.left_justify ? place_left(mods, &ans, size, new_str) :
		place_right(mods, &ans, size, new_str);
	ft_putstr(ans);
	return (size);
}
