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
	while (!((*nptr ^ ' ') || (*nptr ^ '\t') || (*nptr ^ '\n')))
		nptr++;
printf("\nvalue pointed at is :%c", *nptr);
	if ((sign = *nptr == '-' || *nptr == '+' ? 1 : 0))
		sign = *(nptr++) == '-' ? -1 : sign;
printf("\nvalue pointed at is :%c", *nptr);
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
printf("\nvalue pointed at is :%c", *nptr);
printf("\nres is now at :%u", res);
		res = 10 * res + (*(nptr++) - '0');
	}
printf("\nres is now at :%u", res);
	if (res > 0x7fffffff)
		return (-0x80000000 + (int)(res - 0x80000000));
	else
		return ((int)res);
}
