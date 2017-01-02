
#include "ft_printf.h"

int		handle_width(const char *str, t_mods *mods, va_list tags)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		mods->width = va_arg(tags, int);
		return (1);
	}
	while (is_num(str[i]))
		mods->width = mods->width * 10 + (str[i++] - '0');
	return (i);
}

int		handle_precision(const char *str, t_mods *mods, va_list tags)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		if (str[++i] == '*')
		{
			mods->precision = va_arg(tags, int);
			return (1);
		}
		while (is_num(str[i]))
			mods->precision = mods->precision * 10 + (str[i++] - '0');
	}
	return (i);
}
