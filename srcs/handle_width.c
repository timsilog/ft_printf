
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
	while (ft_isdigit(str[i]))
		mods->width = mods->width * 10 + (str[i++] - '0');
	return (i);
}
