/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:52:10 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:52:55 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **last, t_list *new)
{
	t_list	*nxt;

	nxt = *last;
	while ((nxt = nxt->next))
		*last = nxt;
	(**last).next = new;
	while ((nxt = new->next))
		new = nxt;
	*last = new;
}
