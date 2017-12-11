/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:31:14 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:27:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(const char *nptr)
{
	unsigned int		res;
	int					sign;

	if (!nptr)
		return (0);
	while (!((*nptr ^ ' ') && ((*nptr < '\t') || (*nptr > '\r'))))
		nptr++;
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
