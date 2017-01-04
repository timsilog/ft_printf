
#include "ft_printf.c"

int		check_flag_errors(t_mods *mods, int chars_read)
{
	if (mods->flags.left_justify && mods->flags.fill_zeroes)
	{
		ft_putstr("'0' flag ignored with '-' flag.\n");
		return (-1);
	}
	if (mods->flags.show_sign && mods->flags.show_space)
	{
		ft_putstr("' ' flag ignored with '+' flag.\n");
		return (-1);
	}
	return (chars_read);
}

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
	return (check_flag_errors(mods, i));
}

