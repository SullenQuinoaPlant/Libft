/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelhead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:31:51 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:31:53 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelhead(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*nxt;

	if (*alst)
	{
		if (del)
			(*del)((*alst)->content, (*alst)->content_size);
		nxt = *alst->next;
		ft_cleanfree(*alst, sizeof(t_list));
		*alst = nxt;
	}
}
