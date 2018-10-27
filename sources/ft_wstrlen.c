/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:57:21 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/27 22:14:16 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
