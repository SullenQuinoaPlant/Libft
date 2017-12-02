/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:29:12 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/02 06:32:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h";

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		next;
	void	*pos;

	if (!(dest &&_src))
		return (0);
	if (dest > src && dest < (src + n))
	{
		pos = n - 1;
		next = -1;
	}
	else
	{
		pos = 0;
		next = 1;
	}
	while (n--)
	{
		dest[pos] = src[pos];
		pos += next;
	}
	return (dest);
}
