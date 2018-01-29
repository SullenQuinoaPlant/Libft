/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:00:57 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/28 08:15:42 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	check_input(char const *s, unsigned int start, size_t const len)
{
	size_t	new_len;

	new_len = ft_strlen(s);
	new_len -= start < new_len ? start : new_len;
	new_len = len <= new_len ? len : 0;
	return (new_len);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	ss = 0;
	if (s)
	{
		len = check_input(s, start, len);
		if (len && (ss = malloc(len + 1)))
		{
			ss[len] = '\0';
			while (len--)
				ss[len] = s[(size_t)start + len];
		}
	}
	return (ss);
}
