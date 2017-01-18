#include "ft_printf.h"

int main()
{
	//int8_t *b = "asdć";
	ft_printf("my_printf:\n%   ##000    10 hh- d y", 234321);
	printf("\nprintf:\n%  ##000   10 hh - d y", 234321);
	return (0);
}
