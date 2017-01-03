
#include "ft_printf.h"

int		handle_length(const char *str, t_mods *mods)
{
	int i;

	i = 0;
	if (str[i] == 'h')
	{
		if (str[++i] == 'h')
			mods->length = hh;
		else
			mods->length = h;
	}
	else if (str[i] == 'l')
	{
		if (str[++i] == 'l')
			mods->length = ll;
		else
			mods->length = l;
	}
	else if (str[i] == 'j')
		mods->length = j;
	else if (str[i] == 'z')
		mods->length = z;
	else
		return (0);
	return (i + 1);
}
