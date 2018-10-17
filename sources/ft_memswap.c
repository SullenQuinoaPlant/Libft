/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:17:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/09 08:25:56 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_memswap(
	void *a,
	void *b,
	size_t sz)
{
	void *const		lim = a + sz;
	unsigned char	c;
	unsigned char	*pa;
	unsigned char	*pb;

	pa = a;
	pb = b;
	while (a <_lim)
	{
		c = *a;
		*a++ = *b;
		*b++ = c;
	}
}
