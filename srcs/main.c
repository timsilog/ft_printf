#include "ft_printf.h"
#include <limits.h>
#include <sys/types.h>
#include <stddef.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "");

	int test = L'å';
	int temp = test;
	temp = (temp << 2) & 0xff;
	temp >>= 2;
	temp |= 0x80;
	test >>= 6;
	test |= 0xC0;
	printf("%d\n", test);
	char ans[2];
	ans[0] = test;
	ans[1] = temp;
	write(1,ans,2);



	//wint_t b = 'ć';
	char *a = "has";
	//char *b = "asdsadsadsadsadas";
	wint_t b = L'ß';
	//ft_printf("my_printf:\n%x", b);
	//printf("\nprintf:\n%c", b);
	return (0);
}
