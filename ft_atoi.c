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
	unsigned int		ref;
	unsigned int		comp;
	unsigned int		save;
	int					fail;

	while (!((*nptr ^ ' ') && ((*nptr < '\t') || (*nptr > '\r'))))
		nptr++;
	ref = *nptr == '-' ? 0x80000000 : 0x7fffffff;
	*nptr == '-' || *nptr == '+' ? nptr++ : nptr;
	res = 0;
	fail = 0;
	while (!fail && *nptr >= '0' && *nptr <= '9')
	{
		comp = fail ? comp : res << 1;
		res = comp > ref || comp < res ? (fail = 1), ref : comp;
		save = res;
		comp = fail ? comp : res << 1;
		res = comp > ref || comp < res ? (fail = 1), ref : comp;
		comp = fail ? comp : res << 1;
		res = comp > ref || comp < res ? (fail = 1), ref : comp;
		comp = fail ? comp : res + save;
		res = comp > ref || comp < res ? (fail = 1), ref : comp;
		comp = fail ? comp : res + (*nptr++ - '0');
		res = comp > ref || comp < res ? (fail = 1), ref : comp;
	}
	return (ref == 0x80000000 ? (~res) + 1 : res);
}
