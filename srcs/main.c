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
	/*int i = 0;
	char qwe[9];
	ft_wcstombs(qwe,test3,9);
	while (qwe[i])
	{
		int j = 0;
		if ((j = is_mb(&qwe[i])))
		{
			printf("%d, ", qwe[i]);
			i+=j;
		}
		else
			i++;
		ft_putstr(qwe);
	}*/

	ft_printf("my_printf:\n%05.1ls\n", test3);
	printf("\nprintf:\n%05.1ls\n", test3);

	/*debug_d_i_ints();
	debug_d_i_len_mod();
	debug_d_i_precision();
	debug_d_i_space();
	debug_d_i_plus();
	debug_d_i_pound();*/
	return (0);
}
