/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmplen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:52:19 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:56:26 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2, size_t *len)
{
	size_t	index;
	int		diff;

	index = 0;
	while (!(diff = *s1++ - *s2++))
		if (!*s1)
			break;
	return (diff);
}
