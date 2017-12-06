/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:58:48 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:02:09 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	if (!(dest && src))
		return (0);
	while (n--)
	{
		*(dest++) = *(src);
		if (!(*src++))
			break ;
	}
	while (n--)
		*(dest++) = '\0';
	return (dest - n);
}
