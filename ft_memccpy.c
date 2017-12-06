/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:44:21 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 09:19:15 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (!(dest && src))
		return (0);
	while (n-- && (*((char*)src) != (char)c))
	{
		*((char*)dest) = *((char*)src);
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return (n == 0 ? 0 : dest);
}
