#include "ft_printf.h"
#include <limits.h>
#include <sys/types.h>
#include <stddef.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "");

	char ans[7];
	ans[6] = '\0';
	wchar_t test = L'𐄽';
	wchar_t test2 = L'ß';
	/*int temp = test;
	test = (test >> 6) | 0xC0;
	temp = (temp & 0x3f) | 0x80;
	char ans[5];
	ans[0] = test;
	ans[1] = temp;*/
	ft_wctomb(&ans[0], test);
	ft_wctomb(&ans[4], test2);
	/*temp = test2;
	test2 = (test2 >> 6) | 0xC0;
	temp = (temp & 0x3f) | 0x80;
	ans[2] = test2;
	ans[3] = temp;
	ans[4] = '\0';*/
	
	//printf("%s\n",ans);
	wchar_t test3[4] = {L'𐄺', L'å', L'ß', L'\0'};
	/*printf("len = %d\n", ft_wcslen(test3));
	char ans2[ft_wcslen(test3) + 1];
	ft_wcstombs(ans2, test3, ft_wcslen(test3) + 1);
	printf("%s\n", ans2);
	printf("%012.10ls\n1234567890123456789", test3);
*/


	//wint_t b = 'ć';
	char *a = "has";
	//char *b = "asdsadsadsadsadas";
	wint_t b = L'ß';
	ft_printf("my_printf:\n%lc", );
	printf("\nprintf:\n%lc", "asd");
	return (0);
}
