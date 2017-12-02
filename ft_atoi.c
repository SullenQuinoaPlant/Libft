/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:31:14 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/01 10:40:32 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(const char *nptr)
{
	unsigned int		res;
	int					sign;

	if (!nptr)
		return (0);
	while (!((*nptr ^ ' ') && (*nptr ^ '\t') && (*nptr ^ '\n')))
		nptr++;
//	if ((sign = *nptr == '-' || *nptr == '+' ? 1 : 0))
//		sign = *(nptr++) == '-' ? -1 : 1; // this is incomplete, missing an else for case when there is no sign, otherwise always sends zero. which is why switched to below.
	sign = *nptr == '-' || *nptr == '+' ? 44 - *(nptr++) : 1;
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = 10 * res + (*(nptr++) - '0');
	}
	if (res > 0x7fffffff)
		return (sign * (-0x80000000 + (int)(res - 0x80000000)));
	else
		return (sign * (int)res);
}
