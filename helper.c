
#include "ft_printf.h"

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
