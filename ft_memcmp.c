/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:43:36 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/02 08:05:37 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
//	while (n-- && ((char*)s1)[i] == ((char*)s2)[i])
	while (n-- && *((char*)s1++) == *((char*)s2++))
	{
		printf("\nfirst: %c;\tsecond %c", *((char*)s1), *((char*)s2));
		i++;
	}
	return (*(char*)s1 - *(char*)s2);
}
