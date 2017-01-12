/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:33:38 by tjose             #+#    #+#             */
/*   Updated: 2017/01/10 16:33:41 by tjose            ###   ########.fr       */
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

