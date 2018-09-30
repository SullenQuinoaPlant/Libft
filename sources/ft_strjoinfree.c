/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:26:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/30 20:29:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	l;
	char	*s;

	if (!(s1 && s2))
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l = l1 + l2;
	if ((s = malloc(l + 1)))
	{
		l = 0;
		while (*s1 || *s2)
			s[l++] = *s1 ? *s1++ : *s2++;
		s[l] = '\0';
		ft_cleanfree(s1, l1);
		ft_cleanfree(s2, l2);
	}

	return (s);
}
