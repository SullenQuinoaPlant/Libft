/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswapalone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:17:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/09 08:25:56 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memswapalone(
	void *a,
	void *b,
	size_t sz)
{
	void	*buff;

	if (!(buff = malloc(sz)))
		return (-1);
	ft_memcpy(buff, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, buff, sz);
	free(buff);
	return (0);
}
