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
	void *buff,
	size_t sz)
{
	ft_memcpy(buff, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, buff, sz);
}