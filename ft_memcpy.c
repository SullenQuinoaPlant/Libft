/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:44:34 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 08:38:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!(dest && src))
		return (dest);
	while (n--)
		((char*)dest)[n] = ((char*)src)[n];
	return (dest);
}
