/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:52:28 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:56:26 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (!(dest && src))
		return (0);
	i = 0;
	while ((dest[i] = src[i]))
		i++;
	return (dest);
}
