/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:59:32 by tjose             #+#    #+#             */
/*   Updated: 2016/12/29 19:48:51 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

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

int main()
{
	//printf("%d\n%d", fun(4,1,2,3,4), fun(3,2,5,8));
	printf("%+- 6.3d", -14);
}
