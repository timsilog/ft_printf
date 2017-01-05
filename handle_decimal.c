
#include "ft_printf.c"

void	handle_decimal(va_list tags, t_mods *mods)
{
	char	*ans;
	int		n;
	int		i;
	int		

	n = va_arg(tags, int);
	n = convert_length(n, mods);
	if (!(ans = malloc(mods->width)))
		return (-1);
	i = -1;

	while (++i < mods->width)
	{
		if (!mods->flags.left_justify)
		{
			i += width - 
		}
		if (mods->flags.fill_zeroes)
			ans[i] = '0';
		else
			ans[i] = ' ';

	}
	
	return (mods->width);
}
