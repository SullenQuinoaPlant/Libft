/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmplen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:52:19 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 10:19:03 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmplen(const char *s1, const char *s2, size_t len)
{
	const char *const	lim = s1 + len;
	int		diff;

	while (s1 < lim && !(diff = *s1++ - *s2++))
		if (!*s1)
			break;
	return (diff);
}
