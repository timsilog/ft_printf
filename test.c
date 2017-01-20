/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:59:32 by tjose             #+#    #+#             */
/*   Updated: 2017/01/19 20:19:55 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

int fun(int cnt, ...)
{
	int sum = 0;
	va_list lst;
	va_start(lst, cnt);
	int i = 0;
	while (i < cnt)
	{
		int n = va_arg(lst, int);
		sum += n;
		i++;
	}
	return (sum);
}

int num_len(intmax_t n)
{
	int i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int main()
{
	//printf("%d\n%d", fun(4,1,2,3,4), fun(3,2,5,8));
	//int i = (short)12345678;a
	
	setlocale(LC_ALL, "");


	int a = L'ć';
	wchar_t c[] = L"åß∂ƒœ∑´";

//	printf("%5.5+d(ayqweqweqw;;wlrsdfjs%d\n12345678901234567890", 123);
	printf("%d ", printf("'%s'\n",c));
}
