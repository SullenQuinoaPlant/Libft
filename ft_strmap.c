/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:58:18 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:02:09 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ss;
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	if ((ss = malloc(l + 1)))
		while (l--)
			ss[l] = f(s[l]);
	return (ss);
}