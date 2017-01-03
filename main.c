#include "ft_printf.h"

int main()
{
	ft_printf("test%+- #0*.*llhello\n", 42, 53);
	return (0);
}
