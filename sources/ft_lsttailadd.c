/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttailadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:38:53 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:56:47 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsttailadd(t_list **tail, t_list *new)
{
	if (new)
	{
		(**tail).next = new;
		*tail = ft_lstlast(new);
	}
}
